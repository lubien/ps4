#ifndef _HEADSET_H_
#define _HEADSET_H_

#include <string>
#include "device.h"
#include "console.h"
using std::string;
using std::ostream;

class Headset : public Device {
	friend ostream &operator<<(ostream &, const Headset &);
	bool operator== (const Headset &) const;
	bool operator!= (const Headset &other) const {
		return ! (static_cast<Headset>(*this) == other);
	}

	public:
		Headset();
		Headset(int);
		Headset(const Headset &);
		~Headset();
		bool isConnected() const;
		void updateUser(int);
		void connect(const Console &);
		void disconnect();
		void turnOff();

		const Headset &operator=(const Headset &);

	private:
		const Console *console;
		int user;
		int userCount;
		string *usedBy;

		void setupUserList(int);
};

#endif
