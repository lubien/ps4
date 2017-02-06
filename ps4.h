#include <string>
using std::string;
using std::ostream;

class Ps4 {
	friend ostream &operator<<(ostream &, const Ps4 &);
	bool operator== (const Ps4 &) const;
	bool operator!= (const Ps4 &other) const {
		return ! (*this ==other);
	}

	public:
		Ps4();
		Ps4(int);
		Ps4(const Ps4 &);
		~Ps4();
		void setYear(int);
		void addGame(const string &);
		void listGames();
		static int showPublishmentYear();

		const Ps4 &operator=(const Ps4 &);

	private:
		int year;
		string *gameList;
		int gameCount;
		static int publishmentYear;

		void setupGameList(int);
};
