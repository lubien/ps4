#include <iostream>
#include "headset.h"
#include "device.h"
#include "console.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Headset &headset) {
	output << static_cast<Device>(headset) << endl;
	cout << endl;
	cout << (headset.isConnected() ? "Connected" : "Disconnected");
	cout << " Headset" << endl;
	cout << endl;

	return output;
}

bool Headset::operator== (const Headset &other) const {
	if (this->isConnected() != other.isConnected())
		return false;
	if (this->console != other.console)
		return false;
	/* if (static_cast<Device>(*this) != static_cast<Device>(other)) */
	/* 	return false; */

	return true;
}

// Default constructor
Headset::Headset() {
	this->console = NULL;
	this->setupUserList(0);
};

// Constructor
Headset::Headset(int user) {
	this->setupUserList(1);
	this->updateUser(user);
};

Headset::Headset(const Headset &headset) {
	this->console = headset.console;
	this->userCount = headset.userCount;
	this->setupUserList(headset.userCount);

	for (int i = 0; i < this->userCount; i++)
		this->usedBy[i] = headset.usedBy[i];
}

// Destructor
Headset::~Headset() {
	cout << "Destroying Headset"<< endl;

	delete [] this->usedBy;
}

bool Headset::isConnected() const {
	return this->canOperate() && this->console != NULL;
}

void Headset::updateUser(int user) {
	string *aux = new string[this->userCount];

	for (int i = 0; i < this->userCount; i++)
		aux[i] = this->usedBy[i];

	this->setupUserList(++this->userCount);

	for (int i = 0; i < (this->userCount - 1); i++)
		this->usedBy[i] = aux[i];

	this->usedBy[this->userCount - 1] = "Player";
}

void Headset::connect(const Console &console) {
	if (!this->canOperate())
		throw "Cannot connect a headset that's turned off!";

	this->console = &console;
}

void Headset::disconnect() {
	if (!this->canOperate())
		throw "Cannot disconnect a headset that's turned off!";

	this->console = NULL;
	this->user = 0;
}

void Headset::turnOff() {
	this->disconnect();

	this->userCount = 0;
	delete [] this->usedBy;

	Device::turnOff();
}

const Headset& Headset::operator=(const Headset &right) {
	this->console = right.console;
	this->user = right.user;
	this->setupUserList(right.userCount);

	for (int i = 0; i < right.userCount; i++)
		this->usedBy[i] = right.usedBy[i];

	static_cast<Device>(*this) = static_cast<Device>(right);

	return *this;
}

// Private
void Headset::setupUserList(int size) {
	if (size < 1) {
		size = 0;
	}

	if (this->usedBy) {
		delete[] this->usedBy;
	}

	this->usedBy = new string[size];
	this->userCount = size;
}
