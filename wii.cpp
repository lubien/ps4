#include <iostream>
#include "wii.h"
using std::cout;
using std::endl;
using std::ostream;

int Wii::publishmentYear = 2006;

// Public

ostream &operator<<(ostream &output, const Wii &wii) {
	output << "Wii " << wii.year;

	return output;
}

bool Wii::operator== (const Wii &other) const {
	if (this->year != other.year)
		return false;

	return true;
};

// Default constructor
Wii::Wii() {
	this->setupDefaultData();
	this->setYear(publishmentYear);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

// Constructor
Wii::Wii(int year) {
	this->setupDefaultData();
	this->setYear(year);
	this->setupPlayerList(0);
	this->setupGameList(0);
};

Wii::Wii(const Wii &wii) {
	this->setYear(wii.year);
	this->setupPlayerList(wii.playerCount);
	this->setupGameList(wii.games.size());

	for (int i = 0; i < this->playerCount; i++)
		this->players[i] = wii.players[i];

	for (size_t i = 0; i < this->games.size(); i++)
		this->games[i] = wii.games[i];
}

// Destructor
Wii::~Wii() {
	cout << "Destroying Wii " << this->year << endl;
}

void Wii::turnOn() {
	cout << "Tuning on " << *this << endl;
	cout << "Loading Miis at " << *this << endl;
	cout << "Loading game progress at " << *this << endl;
	this->isOn = true;
}

void Wii::turnOff() {
	cout << "Saving game progress at " << *this << endl;

	this->isOn = false;
}

bool Wii::canOperate() const {
	return this->isOn;
}

void Wii::addPlayer(const string &name) {
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

void Wii::removePlayer(const string &name) {
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

void Wii::listPlayers() const {
	this->throwIfCannotOperate();

	cout << "Listing Players for " << *this << endl;

	for (int i = 0; i < this->playerCount; i++) {
		cout << "Player " << this->players[i] << endl;
	}
}

void Wii::addGame(const string &name) {
	this->throwIfCannotOperate();

	if (this->games.size() == 1) {
		throw "Cannot load more than on game at time";
	}

	Game *game = new Game(name);
	this->games.push_back(game);
}

void Wii::removeGame(const string &name) {
	this->throwIfCannotOperate();

	if (this->games.at(0)->getName() != name) {
		throw "This game is not in the console";
	}

	this->games.pop_back();
}

void Wii::listGames() const {
	this->throwIfCannotOperate();

	cout << "Current Game for " << *this << endl;
	cout << (*this->games.at(0)) << endl;
}

const Wii& Wii::operator=(const Wii &right) {
	this->year = right.year;

	this->setupGameList(right.games.size());

	for (size_t i = 0; i < right.games.size(); i++)
		this->games[i] = right.games[i];

	return *this;
}

int Wii::showPublishmentYear() {
	return publishmentYear;
}

// Private

void Wii::throwIfCannotOperate() const {
	if (!this->canOperate()) {
		throw "Cannot operate if you don't turn on this device";
	}
}

void Wii::setYear(int y) {
	if (y < publishmentYear) {
		cout << "Invalid Wii year" << endl;
		cout << "Using publishment year" << endl;
		this->year = publishmentYear;
	} else {
		this->year = y;
	}
}

void Wii::setupPlayerList(int size) {
	if (size < 1) {
		size = 0;
	}

	this->playerCount = size;
	this->players = new string[size];
}

void Wii::setupGameList(int size) {
	if (size < 1) {
		size = 0;
	}

	vector<Game*> games;
	this->games = games;
}

void Wii::setupDefaultData() {
	this->identifier = 444444;
	this->isOn = false;
	this->company = "Nintendo ";
	this->consoleName = "Wii";
	this->generation = 7;
	this->playerCount = 0;
	this->setupGameList(0);
	this->setupPlayerList(0);
}
