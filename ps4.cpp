#include <iostream>
#include "ps4.h"
using std::cout;
using std::endl;
using std::ostream;

int Ps4::publishmentYear = 2014;

// Public

ostream &operator<<(ostream &output, const Ps4 &ps4) {
	output << "Ps4 model " << ps4.year;

	return output;
}

bool Ps4::operator== (const Ps4 &other) const {
	if (this->gameCount != other.gameCount)
		return false;
	if (this->year != other.year)
		return false;

	for (int i = 0; i < this->gameCount; i++)
		if (this->gameList[i] != other.gameList[i])
			return false;

	return true;
}

// Default constructor
Ps4::Ps4() {
	setYear(2017);
	setupGameList(0);
};

// Constructor
Ps4::Ps4(int year) {
	setYear(year);
	setupGameList(0);
};

Ps4::Ps4(const Ps4 &ps4) {
	this->setYear(ps4.year);
	this->setupGameList(0);

	for (int i = 0; i < this->gameCount; i++)
		this->gameList[i] = ps4.gameList[i];
}

// Destructor
Ps4::~Ps4() {
	cout << "Destroying Ps4 model " << this->year << endl;

	delete [] this->gameList;
}

void Ps4::addGame(const string &gameName) {
	string *aux = new string[this->gameCount];

	for (int i = 0; i < this->gameCount; i++)
		aux[i] = this->gameList[i];

	delete [] this->gameList;

	this->gameList = new string[++this->gameCount];

	for (int i = 0; i < (this->gameCount - 1); i++)
		this->gameList[i] = aux[i];

	gameList[this->gameCount - 1] = gameName;

	delete [] aux;
}

void Ps4::listGames() {
	for (int i = 0; i < this->gameCount; i++)
		cout << "Game [" << i + 1 << "] " << this->gameList[i] << endl;
}

const Ps4& Ps4::operator=(const Ps4 &right) {
	this->year = right.year;
	this->gameCount = right.gameCount;

	delete [] this->gameList;

	this->gameList = new string[right.gameCount];

	for (int i = 0; i < right.gameCount; i++)
		this->gameList[i] = right.gameList[i];

	return *this;
}

int Ps4::showPublishmentYear() {
	return publishmentYear;
}

// Private

void Ps4::setupGameList(int size) {
	if (size < 1) {
		size = 0;
	}

	this->gameList = new string[size];
	this->gameCount = size;

	cout << "Started Ps4 object with " << size << " games" << endl;
}

void Ps4::setYear(int y) {
	if (y < publishmentYear) {
		cout << "Invalid year" << endl;
		this->setYear(1941);
	} else {
		year = y;
	}
}
