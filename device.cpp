#include <iostream>
#include "device.h"
using std::cout;
using std::endl;
using std::ostream;

// Public

ostream &operator<<(ostream &output, const Device &device) {
	output << (device.isOn ? "On" : "Off") << " Device";

	return output;
}

bool Device::operator== (const Device &other) const {
	if (this->hasPowerSupply != other.hasPowerSupply)
		return false;
	if (this->isOn != other.isOn)
		return false;

	return true;
}

// Default constructor
Device::Device() {
	this->isOn = false;
	this->hasPowerSupply = false;
};

// Constructor
Device::Device(bool isOn, bool hasPowerSupply) {
	this->isOn = isOn;
	this->hasPowerSupply = hasPowerSupply;
};

Device::Device(const Device &device) {
	this->isOn = device.isOn;
	this->hasPowerSupply = device.hasPowerSupply;
}

// Destructor
Device::~Device() {
	cout << "Destroying Device"<< endl;
}

void Device::turnOn() {
	if (!this->hasPowerSupply) {
		throw "Can't turn on device without power supply";
	}

	if (this->isOn) {
		throw "Already On";
	}

	this->isOn = true;
}

void Device::turnOff() {
	if (!this->hasPowerSupply) {
		throw "Can't turn off device without power supply";
	}

	if (!this->isOn) {
		throw "Already Off";
	}

	this->isOn = false;
}

void Device::plugPowerSupply() {
	if (this->hasPowerSupply) {
		throw "Already have power supply";
	}

	this->hasPowerSupply = true;
}

void Device::unPlugPowerSupply() {
	if (!this->hasPowerSupply) {
		throw "Doesn't have power supply";
	}

	this->isOn = false;
	this->hasPowerSupply = false;
}

bool Device::canOperate() const {
	return this->hasPowerSupply && this->isOn;
}

const Device& Device::operator=(const Device &right) {
	this->isOn = right.isOn;
	this->hasPowerSupply = right.hasPowerSupply;

	return *this;
}
