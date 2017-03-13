#include <iostream>
#include <vector>
#include "ps4.h"
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

int Ps4::publishmentYear = 2014;

// Public

ostream &operator<<(ostream &output, const Ps4 &ps4) {
	output << "Ps4 model " << ps4.year;

	return output;
}

bool Ps4::operator== (const Ps4 &other) const {
	if (this->year != other.year)
		return false;

	return true;
};

// Default constructor
Ps4::Ps4() {
	this->setupDefaultData();
	this->setYear(publishmentYear);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

// Constructor
Ps4::Ps4(int year) {
	this->setupDefaultData();
	this->setYear(year);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

Ps4::Ps4(const Ps4 &ps4) {
	this->setYear(ps4.year);
	this->setupPlayerList(ps4.playerCount);
	this->setupGameList(ps4.games.size());

	for (int i = 0; i < this->playerCount; i++)
		this->players[i] = ps4.players[i];

	for (size_t i = 0; i < this->games.size(); i++)
		this->games[i] = ps4.games[i];
}

// Destructor
Ps4::~Ps4() {
	cout << "Destroying Ps4 model " << this->year << endl;
}

void Ps4::turnOn() {
	cout << "Tuning on " << *this << endl;
	cout << "Loading games progress at " << *this << endl;
	this->isOn = true;
}

void Ps4::turnOff() {
	cout << "Saving games progress at " << *this << endl;

	this->isOn = false;
}

bool Ps4::canOperate() const {
	return this->isOn;
}

void Ps4::addPlayer(const string &name) {
	this->throwIfCannotOperate();

	string *aux = new string[this->playerCount];

	for (int i = 0; i < this->playerCount; i++)
		aux[i] = this->players[i];

	delete [] this->players;
	this->setupPlayerList(this->playerCount + 1);

	for (int i = 0; i < (this->playerCount - 1); i++)
		this->players[i] = aux[i];

	this->players[this->playerCount - 1] = name;

	delete [] aux;
}

void Ps4::removePlayer(const string &name) {
	this->throwIfCannotOperate();

	string *aux = new string[this->playerCount];

	for (int i = 0; i < this->playerCount; i++)
		aux[i] = this->players[i];

	delete [] this->players;
	this->setupPlayerList(this->playerCount - 1);

	for (int i = 0, j = 0; j < (this->playerCount + 1); j++) {
		if (aux[j] != name) {
			this->players[i] = aux[j];
			i++;
		}
	}

	delete [] aux;
}

void Ps4::listPlayers() const {
	this->throwIfCannotOperate();

	cout << "Listing Players for " << *this << endl;

	for (int i = 0; i < this->playerCount; i++) {
		cout << "Player " << this->players[i] << endl;
	}
}

void Ps4::addGame(const string &name) {
	this->throwIfCannotOperate();

	Game *game = new Game(name);
	this->games.push_back(game);
}

void Ps4::removeGame(const string &name) {
	this->throwIfCannotOperate();

	int toDelete = -1;

	for (size_t i = 0; i < this->games.size(); i++) {
		if (this->games.at(i)->getName() == name) {
			toDelete = i;
		}
	}

	if (toDelete == -1) {
		throw "Game doesn't exists";
	}

	this->games.erase(this->games.begin() + toDelete);
}

void Ps4::listGames() const {
	this->throwIfCannotOperate();

	cout << "Listing Games for " << *this << endl;

	for (size_t i = 0; i < this->games.size(); i++) {
		cout << (*this->games.at(i)) << endl;
	}
}

const Ps4& Ps4::operator=(const Ps4 &right) {
	this->year = right.year;

	this->setupGameList(right.games.size());

	for (size_t i = 0; i < right.games.size(); i++)
		this->games[i] = right.games[i];

	return *this;
}

int Ps4::showPublishmentYear() {
	return publishmentYear;
}

// Private

void Ps4::throwIfCannotOperate() const {
	if (!this->canOperate()) {
		throw "Cannot operate if you don't turn on this device";
	}
}

void Ps4::setYear(int y) {
	if (y < publishmentYear) {
		cout << "Invalid Ps4 year" << endl;
		cout << "Using publishment year" << endl;
		this->year = publishmentYear;
	} else {
		this->year = y;
	}
}

void Ps4::setupPlayerList(int size) {
	if (size < 1) {
		size = 0;
	}

	this->playerCount = size;
	this->players = new string[size];
}

void Ps4::setupGameList(int size) {
	if (size < 1) {
		size = 0;
	}

	vector<Game*> games;
	this->games = games;
}

void Ps4::setupDefaultData() {
	this->identifier = 444444;
	this->isOn = false;
	this->company = "Sony";
	this->consoleName = "PlayStation 4";
	this->generation = 8;
	this->playerCount = 0;
	this->setupGameList(0);
	this->setupPlayerList(0);
}
