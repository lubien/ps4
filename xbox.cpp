#include <iostream>
#include <vector>
#include "xbox.h"
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

int Xbox::publishmentYear = 2001;

// Public

ostream &operator<<(ostream &output, const Xbox &xbox) {
	output << "Xbox " << xbox.year;

	return output;
}

bool Xbox::operator== (const Xbox &other) const {
	if (this->year != other.year)
		return false;

	return true;
};

// Default constructor
Xbox::Xbox() {
	this->setupDefaultData();
	this->setYear(publishmentYear);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

// Constructor
Xbox::Xbox(int year) {
	this->setupDefaultData();
	this->setYear(year);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

Xbox::Xbox(const Xbox &xbox) {
	this->setYear(xbox.year);
	this->setupPlayerList(xbox.playerCount);
	this->setupGameList(xbox.games.size());

	for (int i = 0; i < this->playerCount; i++)
		this->players[i] = xbox.players[i];

	for (size_t i = 0; i < this->games.size(); i++)
		this->games[i] = xbox.games[i];
}

// Destructor
Xbox::~Xbox() {
	cout << "Destroying Xbox " << this->year << endl;
}

void Xbox::turnOn() {
	cout << "Tuning on " << *this << endl;
	this->isOn = true;
}

void Xbox::turnOff() {
	cout << "Saving game progress at " << *this << endl;

	this->isOn = false;
}

bool Xbox::canOperate() const {
	return this->isOn;
}

void Xbox::addPlayer(const string &name) {
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

void Xbox::removePlayer(const string &name) {
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

void Xbox::listPlayers() const {
	this->throwIfCannotOperate();

	cout << "Listing Players for " << *this << endl;

	for (int i = 0; i < this->playerCount; i++) {
		cout << "Player " << this->players[i] << endl;
	}
}

void Xbox::addGame(const string &name) {
	this->throwIfCannotOperate();

	if (this->games.size() == 1) {
		throw "Cannot load more than on game at time";
	}

	Game *game = new Game(name);
	this->games.push_back(game);
}

void Xbox::removeGame(const string &name) {
	this->throwIfCannotOperate();

	if (this->games.at(0)->getName() != name) {
		throw "This game is not in the console";
	}

	this->games.pop_back();
}

void Xbox::listGames() const {
	this->throwIfCannotOperate();

	cout << "Current Game for " << *this << endl;
	cout << (*this->games.at(0)) << endl;
}

const Xbox& Xbox::operator=(const Xbox &right) {
	this->year = right.year;

	this->setupGameList(right.games.size());

	for (size_t i = 0; i < right.games.size(); i++)
		this->games[i] = right.games[i];

	return *this;
}

int Xbox::showPublishmentYear() {
	return publishmentYear;
}

// Private

void Xbox::throwIfCannotOperate() const {
	if (!this->canOperate()) {
		throw "Cannot operate if you don't turn on this device";
	}
}

void Xbox::setYear(int y) {
	if (y < publishmentYear) {
		cout << "Invalid Xbox year" << endl;
		cout << "Using publishment year" << endl;
		this->year = publishmentYear;
	} else {
		this->year = y;
	}
}

void Xbox::setupPlayerList(int size) {
	if (size < 1) {
		size = 0;
	}

	this->playerCount = size;
	this->players = new string[size];
}

void Xbox::setupGameList(int size) {
	if (size < 1) {
		size = 0;
	}

	vector<Game*> games;
	this->games = games;
}

void Xbox::setupDefaultData() {
	this->identifier = 333333;
	this->isOn = false;
	this->company = "Microsoft Corporation";
	this->consoleName = "Xbox";
	this->generation = 6;
	this->playerCount = 0;
	this->setupGameList(0);
	this->setupPlayerList(0);
}
