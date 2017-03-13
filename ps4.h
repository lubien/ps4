#ifndef _PS4_H_
#define _PS4_H_

#include <string>
#include "device.h"
#include "console.h"
#include "game.h"
using std::string;
using std::ostream;

class Ps4 : public Console {
	friend ostream &operator<<(ostream &, const Ps4 &);
	bool operator== (const Ps4 &) const;
	bool operator!= (const Ps4 &other) const {
		return ! ((*this) == other);
	}

	public:
		Ps4();
		Ps4(int);
		Ps4(const Ps4 &);
		~Ps4();
		void turnOn();
		void turnOff();
		bool canOperate() const;
		void addPlayer(const string &);
		void removePlayer(const string &);
		void listPlayers() const;
		void addGame(const string &);
		void removeGame(const string &);
		void listGames() const;

		static int showPublishmentYear();

		const Ps4 &operator=(const Ps4 &);

	private:
		static int publishmentYear;
		int year;

		void throwIfCannotOperate() const;
		void setYear(int);
		void setupGameList(int);
		void setupPlayerList(int);
		void setupDefaultData();
};

#endif
