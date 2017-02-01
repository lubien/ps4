#include <string>
using std::string;
using std::ostream;

class Ps4 {
	friend ostream &operator<<(ostream &, const Ps4 &);
	public:
		Ps4();
		Ps4(int, int);
		void ~Ps4();
		void setYear(int);
		void addGame(const string &);
		void listGames();

		const Ps4 &operator=(const Ps4 &);

	private:
		int year;
		string *gameList;
		int gameCount;

		void setupGameList(int);
};
