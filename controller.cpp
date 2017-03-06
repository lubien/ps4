#include <iostream>
#include "controller.h"
#include "device.h"
#include "console.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Controller &controller) {
	output << static_cast<Device>(controller) << endl;
	cout << endl;
	cout << (controller.isConnected() ? "Connected" : "Disconnected");
	cout << " Controller" << endl;
	cout << endl;

	return output;
}

bool Controller::operator== (const Controller &other) const {
	if (this->isConnected() != other.isConnected())
		return false;
	if (this->console != other.console)
		return false;
	/* if (static_cast<Device>(*this) != static_cast<Device>(other)) */
	/* 	return false; */

	return true;
}

// Default constructor
Controller::Controller() {
	this->console = NULL;
	this->setupUserList(0);
};

// Constructor
Controller::Controller(int user) {
	this->setupUserList(1);
	this->updateUser(user);
};

Controller::Controller(const Controller &controller) {
	this->console = controller.console;
	this->userCount = controller.userCount;
	this->setupUserList(controller.userCount);

	for (int i = 0; i < this->userCount; i++)
		this->usedBy[i] = controller.usedBy[i];
}

// Destructor
Controller::~Controller() {
	cout << "Destroying Controller"<< endl;

	delete [] this->usedBy;
}

bool Controller::isConnected() const {
	return this->canOperate() && this->console != NULL;
}

void Controller::updateUser(int user) {
	string *aux = new string[this->userCount];

	for (int i = 0; i < this->userCount; i++)
		aux[i] = this->usedBy[i];

	this->setupUserList(++this->userCount);

	for (int i = 0; i < (this->userCount - 1); i++)
		this->usedBy[i] = aux[i];

	this->usedBy[this->userCount - 1] = "Player";
}

void Controller::connect(const Console &console) {
	if (!this->canOperate())
		throw "Cannot connect a controller that's turned off!";

	this->console = &console;
}

void Controller::disconnect() {
	if (!this->canOperate())
		throw "Cannot disconnect a controller that's turned off!";

	this->console = NULL;
	this->user = 0;
}

void Controller::turnOff() {
	this->disconnect();

	this->userCount = 0;
	delete [] this->usedBy;

	Device::turnOff();
}

const Controller& Controller::operator=(const Controller &right) {
	this->console = right.console;
	this->user = right.user;
	this->setupUserList(right.userCount);

	for (int i = 0; i < right.userCount; i++)
		this->usedBy[i] = right.usedBy[i];

	static_cast<Device>(*this) = static_cast<Device>(right);

	return *this;
}

// Private
void Controller::setupUserList(int size) {
	if (size < 1) {
		size = 0;
	}

	if (this->usedBy) {
		delete[] this->usedBy;
	}

	this->usedBy = new string[size];
	this->userCount = size;
}
