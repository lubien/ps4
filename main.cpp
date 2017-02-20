#include <iostream>
#include <string>
#include "device.h"
#include "console.h"
#include "ps4.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	// Static
	cout << "Playstation was published at " << Ps4::showPublishmentYear() << endl << endl;
	// Constructor
	Device myDevice(false, false);
	Console myConsole("Nintendo", 10, 4, 0);
	Ps4 myPs4(2016);

	// Default construtor
	Device defaultDevice;
	Console defaultConsole;
	Ps4 defaultPs4;

	// Copy constructor
	Device copyDevice = myDevice;
	Console copyConsole = myConsole;
	Ps4 copyPs4 = myPs4;

	cout << endl << "Constructors:" << endl << endl;

	cout << "Constructor :: " << myDevice << endl;
	cout << "Constructor :: " << myConsole << endl;
	cout << "Constructor :: " << myPs4 << endl;
	cout << "Default     :: " << defaultDevice << endl;
	cout << "Default     :: " << defaultConsole << endl;
	cout << "Default     :: " << defaultPs4 << endl;
	cout << "Copy        :: " << copyDevice << endl;
	cout << "Copy        :: " << copyConsole << endl;
	cout << "Copy        :: " << copyPs4 << endl;

	cout << endl;

	myPs4.addGame("game1");
	myPs4.addGame("game2");
	myPs4.addGame("game3");

	myPs4.listGames();
	cout << endl;

	myPs4.addGame("game4");
	myPs4.addGame("game5");

	myPs4.listGames();

	// From Device
	myPs4.plugPowerSupply();

	// Virtual on Device
	myPs4.turnOn();
	myPs4.turnOff();

	cout << endl;
}
