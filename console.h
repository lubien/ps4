#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>
#include <vector>
#include "device.h"
#include "game.h"
using std::string;
using std::ostream;
using std::vector;

class Console : public Device {
	friend ostream &operator<<(ostream &, const Console &);
	bool operator== (const Console &) const;
	bool operator!= (const Console &other) const {
		return ! ((*this) ==other);
	}

	public:
		Console();
		Console(const string &, const string &, int);
		Console(const Console &);
		~Console();
		virtual void addPlayer(const string &) = 0;
		virtual void removePlayer(const string &) = 0;
		virtual void listPlayers() const = 0;
		virtual void addGame(const string &) = 0;
		virtual void removeGame(const string &) = 0;
		virtual void listGames() const = 0;

		const Console &operator=(const Console &);

	protected:
		string company;
		string consoleName;
		int generation;
		int playerCount;
		string *players;
		vector<Game*> games;
};

#endif
