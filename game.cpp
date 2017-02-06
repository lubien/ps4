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
	return this->name == other.name;
}

// Constructor
Game::Game(const string &name) {
	this->name = name;
};

/* // Destructor */
/* Game::~Game() { */
/* 	cout << "Destroying " << (*this) << endl; */
/* } */

const Game& Game::operator=(const Game &right) {
	this->name = right.name;
	return *this;
}
