#include <iostream>
#include <string>
#include "ps4.h"
using std::cout;
using std::endl;
using std::string;
/*
	 * Uma nova classe relacionada ao seu projeto
	 Duas alocações dinâmicas de memória - uma similar ao do exemplo do livro - slide 85
	 * Uso explicito do ponteiro this
	 Uso do destrutor
	 Sobrecarga dos operadores
		 = (atribuição)
		 ==
		 ~=
		 operador <<
	 *3 construtores - incluindo um de cópia
	 *2 métodos - não pode ser get ou set
	 *1 método extra que precisa ser const
	 1 atributo static - inicializar no cpp
	 1 atributo static const - inicializar no cpp
	 1 método static - mostrar o seu uso no main
	 Composição com classe Data
	 1 array  - precisa ser realmente usado
 */
int main() {
	// Static
	cout << "Playstation was published at " << Ps4::showPublishmentYear() << endl << endl;
	// Constructor
	Ps4 myPs4(2016);

	// Default construtor
	Ps4 defaultPs4;

	// Copy constructor
	Ps4 copyPs4 = myPs4;

	cout << "Constructors:" << endl << endl;

	cout << "Constructor :: " << myPs4 << endl;
	cout << "Default     :: " << defaultPs4 << endl;
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
	cout << endl;
}
