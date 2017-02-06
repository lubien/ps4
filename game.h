#include <string>
using std::string;
using std::ostream;

class Game {
	friend ostream &operator<<(ostream &, const Game &);
	bool operator== (const Game &) const;
	bool operator!= (const Game &other) const {
		return ! (*this == other);
	}

	public:
		Game(const string &);
		/* ~Game(); */

		const Game &operator=(const Game &);

	private:
		string name;
};
