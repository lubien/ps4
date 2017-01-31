#include <iostream>
#include "ps4.h"
using std::cout;
using std::endl;

// Public

Ps4::Ps4() {
	setYear(2017);
	setupGameList(0);
};

Ps4::Ps4(int year, int gameCount) {
	setYear(year);
	setupGameList(gameCount);
};

Ps4::~Ps4() {
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
		cout << "[" << i << "] " << this->gameList[i] << endl;
}

// Private

void Ps4::setupGameList(int size) {
	if (size < 1) {
		size = 0;
	}

	this->gameList = new string[size];
	this->gameCount = size;

	cout << "Started Ps4 object with " << size << " books" << endl;
}

void Ps4::setYear(int y) {
	if (y < 2013) {
		cout << "Invalid year" << endl;
	} else {
		year = y;
	}
}
