#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>
#include "device.h"
using std::string;
using std::ostream;

class Console : public Device {
	friend ostream &operator<<(ostream &, const Console &);
	bool operator== (const Console &) const;
	bool operator!= (const Console &other) const {
		return ! (static_cast<Console>(*this) ==other);
	}

	public:
		Console();
		Console(const string &, int, int, int);
		Console(const Console &);
		~Console();
		void addPlayer();
		void removePlayer();
		void listGames();

		const Console &operator=(const Console &);

	protected:
		string company;
		int generation;
		int maxPlayers;
		int numPlayers;
};

#endif
