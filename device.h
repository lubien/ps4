#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <string>
using std::string;
using std::ostream;

class Device {
	friend ostream &operator<<(ostream &, const Device &);
	bool operator== (const Device &) const;
	bool operator!= (const Device &other) const {
		return ! ((*this) == other);
	}

	public:
		Device();
		Device(int, bool);
		Device(const Device &);
		~Device();
		virtual void turnOn() = 0;
		virtual void turnOff() = 0;
		virtual bool canOperate() const = 0;

		const Device &operator=(const Device &);

	protected:
		int identifier;
		bool isOn;
};

#endif
