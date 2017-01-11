#include <iostream>
#include "ps4.h"
using std::cout;
using std::endl;

Ps4::Ps4() {
	setYear(2017);
};

void Ps4::setYear(int y) {
	if (y < 2013) {
		cout << "Invalid year" << endl;
	} else {
		year = y;
	}
}
