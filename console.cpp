#include <iostream>
#include "console.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Console &console) {
	string generationSuffix;

	switch(console.generation) {
		case 1:
			generationSuffix = "st";
			break;
		case 2:
			generationSuffix = "nd";
			break;
		case 3:
			generationSuffix = "rd";
			break;
		default:
			generationSuffix = "th";
			break;
	}


	output << console.company << " " << console.consoleName << " "
		<< console.generation << generationSuffix
		<< " generation [" << console.playerCount << " players]";

	return output;
}

bool Console::operator== (const Console &other) const {
	if (this->company != other.company)
		return false;
	if (this->generation != other.generation)
		return false;
	if (this->playerCount != other.playerCount)
		return false;

	for (int i; i < this->playerCount; i++) {
		if (this->players[i] != other.players[i]) {
			return false;
		}
	}

	for (size_t i; i < this->games.size(); i++) {
		if (this->games[i] != other.games[i]) {
			return false;
		}
	}

	return true;
}

// Default constructor
Console::Console() {
	this->company = "Anonymous Company";
	this->consoleName = "Anonymous Console";
	this->generation = 0;
	this->playerCount = 0;
	this->players = new string[0];
	vector<Game*> games;
	this->games = games;
};

// Constructor
Console::Console(const string &company, const string &name, int generation) {
	this->company = company;
	this->consoleName = name;
	this->generation = generation;
	this->playerCount = 0;
	this->players = new string[0];
	vector<Game*> games;
	this->games = games;
};

Console::Console(const Console &console) {
	this->company = console.company;
	this->consoleName = console.consoleName;
	this->generation = console.generation;
	this->playerCount = console.playerCount;
	this->players = new string[this->playerCount];
	vector<Game*> games;
	this->games = games;

	for (int i; i < this->playerCount; i++) {
		this->players[i] = console.players[i];
	}

	for (size_t i; i < console.games.size(); i++) {
		this->games[i] = console.games[i];
	}
}

// Destructor
Console::~Console() {
	cout << "Destroying " << *this << endl;
	delete [] this->players;
}

const Console& Console::operator=(const Console &right) {
	this->company = right.company;
	this->consoleName = right.consoleName;
	this->generation = right.generation;
	this->playerCount = right.playerCount;

	delete [] this->players;
	this->players = new string[this->playerCount];
	vector<Game*> games;
	this->games = games;

	for (int i; i < this->playerCount; i++) {
		this->players[i] = right.players[i];
	}

	for (size_t i; i < right.games.size(); i++) {
		this->games[i] = right.games[i];
	}

	return *this;
}
