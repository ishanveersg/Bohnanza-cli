#include "Card.h"

class Quartz : public Card {

public:
	const int NUMCARDS = 20;

	int getCardsPerCoin(int coins) {
		if (0 < coins && coins < 5)
			return 2 * coins + 2;
		return 0;
	}

	string getName() {
		return "Quartz";
	}

	void print(ostream& out) const {
		out << "Q";
	}
};