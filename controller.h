#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <string>
#include "device.h"
#include "console.h"
using std::string;
using std::ostream;

class Controller : public Device {
	friend ostream &operator<<(ostream &, const Controller &);
	bool operator== (const Controller &) const;
	bool operator!= (const Controller &other) const {
		return ! (static_cast<Controller>(*this) == other);
	}

	public:
		Controller();
		Controller(int);
		Controller(const Controller &);
		~Controller();
		bool isConnected() const;
		void updateUser(int);
		void connect(const Console &);
		void disconnect();
		void turnOff();

		const Controller &operator=(const Controller &);

	private:
		const Console *console;
		int user;
		int userCount;
		string *usedBy;

		void setupUserList(int);
};

#endif
