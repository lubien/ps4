#ifndef _GAME_H
#define _GAME_H

#include <string>
using std::string;
using std::ostream;

class Game {
	friend ostream &operator<<(ostream &, const Game &);
	bool operator== (const Game &) const;
	bool operator!= (const Game &other) const {
		return ! (*this == other);
	}

	public:
		Game();
		Game(const string &);
		Game(const Game &);
		~Game();
		string getName();

		const Game &operator=(const Game &);

	private:
		string name;
};

#endif
