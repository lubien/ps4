#ifndef _WII_H_
#define _WII_H_

#include <string>
#include "device.h"
#include "console.h"
#include "game.h"
using std::string;
using std::ostream;

class Wii : public Console {
	friend ostream &operator<<(ostream &, const Wii &);
	bool operator== (const Wii &) const;
	bool operator!= (const Wii &other) const {
		return ! ((*this) == other);
	}

	public:
		Wii();
		Wii(int);
		Wii(const Wii &);
		~Wii();
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

		const Wii &operator=(const Wii &);

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
