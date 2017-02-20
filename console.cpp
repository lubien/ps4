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


	output << console.company << " console "
		<< console.generation << generationSuffix
		<< " generation [" << console.numPlayers
		<< "/" << console.maxPlayers << " players]";

	return output;
}

bool Console::operator== (const Console &other) const {
	if (this->company != other.company)
		return false;
	if (this->generation != other.generation)
		return false;
	if (this->maxPlayers != other.maxPlayers)
		return false;

	return true;
}

// Default constructor
Console::Console() {
	this->company = "Anonymous Co.";
	this->generation = 0;
	this->maxPlayers = 1;
	this->numPlayers = 0;
};

// Constructor
Console::Console(
	const string &company, int generation, int maxPlayers, int numPlayers
) {
	this->company = company;
	this->generation = generation;
	this->maxPlayers = maxPlayers;
	this->numPlayers = numPlayers;
};

Console::Console(const Console &console) {
	this->company = console.company;
	this->generation = console.generation;
	this->maxPlayers = console.maxPlayers;
	this->numPlayers = console.numPlayers;
}

// Destructor
Console::~Console() {
	cout << "Destroying Console " << *this << endl;
}

void Console::addPlayer() {
	if (this->numPlayers == this->maxPlayers) {
		throw "Too many players";
	}

	this->numPlayers++;
}

void Console::removePlayer() {
	if (this->numPlayers == 0) {
		throw "Can't remove a player that doesn't exists";
	}

	this->numPlayers--;
}

const Console& Console::operator=(const Console &right) {
	this->company = right.company;
	this->generation = right.generation;
	this->maxPlayers = right.maxPlayers;
	this->numPlayers = right.numPlayers;

	return *this;
}
