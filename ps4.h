#include <string>
using std::string;

class Ps4 {
	public:
		Ps4();
		Ps4(int, int);
		void ~Ps4();
		void setYear(int);
		void addGame(const string &);
		void listGames();

	private:
		int year;
		string *gameList;
		int gameCount;

		void setupGameList(int);
};
