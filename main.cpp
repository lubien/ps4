#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "device.h"
#include "console.h"
#include "controller.h"
#include "headset.h"
#include "ps4.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector < Device * > devices(3);
	devices[0] = new Console("Nintendo", 10, 4, 1);
	devices[1] = new Controller(1);
	devices[2] = new Headset(1);

	for (size_t i = 0; i < devices.size(); i++) {
		cout << i << endl;
		cout << (*devices[i]) << endl;

		Console *derivedPtr = dynamic_cast<Console*>(devices[i]);

		if (derivedPtr != 0) {
			cout << (*derivedPtr) << endl;
		}
	}

	for (size_t i = 0; i < devices.size(); i++) {
		// Não coloquei um cout porque eles acontecem dentro da classe
		delete devices[i];
	}
}
