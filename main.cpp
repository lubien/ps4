#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "device.h"
#include "console.h"
#include "ps4.h"
#include "wii.h"
#include "xbox.h"
#include "game.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector < Device * > devices(3);
	devices[0] = new Ps4(2017);
	devices[1] = new Xbox;
	devices[2] = new Wii;

	for (size_t i = 0; i < devices.size(); i++) {
		cout << i << endl;
		cout << (*devices[i]) << endl;

		Console *derivedPtr = dynamic_cast<Console*>(devices[i]);

		if (derivedPtr != 0) {
			cout << (*derivedPtr) << endl << endl;
		}
	}

	for (size_t i = 0; i < devices.size(); i++) {
		// Não coloquei um cout porque eles acontecem dentro da classe
		delete devices[i];
	}
}
