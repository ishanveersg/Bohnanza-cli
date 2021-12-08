#include "Deck.h"
#include "CardFactory.h"

Deck::Deck(std::istream& istr, CardFactory* _cFactory){
	
	Deck temp;
	std::string line;	std::getline(istr, line);
	std::istringstream record(line);
	char char_;
	while (record.get(char_)) {
		if (char_ != ' ') 	temp.push_back(_cFactory->getCard(char_));
	}
	new (&(*this)) Deck(temp);  // Re-construct itself using default copy constructor(shallow copy)
}

Card* Deck::draw()
{
	if (empty()) return nullptr;
	else {
		Card* card = back();
		pop_back();
		return card;
	}
}

std::ostream& operator<<(std::ostream& ostr, Deck& _deck)
{
	for (auto& c : _deck) {
		ostr << *c;
	}
	return ostr;
}
