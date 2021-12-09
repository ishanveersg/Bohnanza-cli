#ifndef CardFactory_h
#define CardFactory_h
#include <random>
#include <algorithm>
#include <iterator>
#include "Deck.h"
#include "Card.h"
#include "Beans.h"

class Deck;

class CardFactory {
	Deck *d_deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
	Card* getCard(char);
	Deck setDeck (istream &);
};
#endif
