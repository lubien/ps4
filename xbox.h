#ifndef _XBOX_H_
#define _XBOX_H_

#include <string>
#include "device.h"
#include "console.h"
#include "game.h"
using std::string;
using std::ostream;

class Xbox : public Console {
	friend ostream &operator<<(ostream &, const Xbox &);
	bool operator== (const Xbox &) const;
	bool operator!= (const Xbox &other) const {
		return ! ((*this) == other);
	}

	public:
		Xbox();
		Xbox(int);
		Xbox(const Xbox &);
		~Xbox();
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

		const Xbox &operator=(const Xbox &);

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
