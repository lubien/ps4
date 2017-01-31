#include <iostream>
#include <string>
#include "ps4.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	Ps4 myPs4(2017, 3);

	cout << "Hello World" << endl;

	myPs4.addGame("game1");
	myPs4.addGame("game2");
	myPs4.addGame("game3");

	myPs4.listGames();

	myPs4.addGame("game4");
	myPs4.addGame("game5");

	myPs4.listGames();
}
