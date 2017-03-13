#include <iostream>
#include "game.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Game &game) {
	output << "Game(" << game.name << ")";

	return output;
}

bool Game::operator== (const Game &other) const {
	cout << "compare" << *this << " :: " << other << endl;
	return this->name == other.name;
}

// Default Constructor
Game::Game() {
	cout << "New unnamed game " << endl;
	this->name = "Unnamed";
};

// Constructor
Game::Game(const string &name) {
	cout << "New game " << name << endl;
	this->name = name;
};

Game::Game(const Game &game) {
	this->name = game.name;
}

/* // Destructor */
Game::~Game() {
	cout << "Destroying " << (*this) << endl;
}

string Game::getName() {
	return this->name;
}

const Game& Game::operator=(const Game &right) {
	this->name = right.name;
	return *this;
}
