#include <vector>
#include <sstream>
#include <iostream>
#include "Beans.h"

class Deck : public std::vector<Card*> {
public:
	Deck() = default;
	Deck(std::istream&, class CardFactory*);
	Card* draw();
	friend std::ostream& operator<<(std::ostream&, Deck&);
};
