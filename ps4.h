#ifndef _PS4_H_
#define _PS4_H_

#include <string>
#include "console.h"
#include "game.h"
using std::string;
using std::ostream;

class Ps4 : public Console {
	friend ostream &operator<<(ostream &, const Ps4 &);
	bool operator== (const Ps4 &) const;
	bool operator!= (const Ps4 &other) const {
		return ! (static_cast<Ps4>(*this) ==other);
	}

	public:
		Ps4();
		Ps4(int);
		Ps4(const Ps4 &);
		~Ps4();
		void setYear(int);
		void addGame(const string &);
		void listGames();
		void turnOn();
		void turnOff();
		static int showPublishmentYear();

		const Ps4 &operator=(const Ps4 &);

	private:
		int year;
		string *gameList;
		int gameCount;
		static int publishmentYear;

		void setupGameList(int);
		void setupDefaultConsoleData();
};

#endif
