#include <iostream>
#include "device.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Device &device) {
	output << "Device " << device.identifier << " ["
		<< (device.isOn ? "On" : "Off") << "]";

	return output;
}

bool Device::operator== (const Device &other) const {
	if (this->identifier != other.identifier)
		return false;
	if (this->isOn != other.isOn)
		return false;

	return true;
}

// Default constructor
Device::Device() {
	this->identifier = 0;
	this->isOn = false;
};

// Constructor
Device::Device(int identifier, bool isOn) {
	this->identifier = identifier;
	this->isOn = isOn;
};

Device::Device(const Device &device) {
	this->identifier = device.identifier;
	this->isOn = device.isOn;
}

// Destructor
Device::~Device() {
	cout << "Destroying Device"<< endl;
}

const Device& Device::operator=(const Device &right) {
	this->identifier = right.identifier;
	this->isOn = right.isOn;

	return *this;
}
