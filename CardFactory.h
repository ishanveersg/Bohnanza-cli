#include <list>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>
#include "Deck.h"
#include "Card.h"
#include "Beans.h"


class CardFactory {
private:
    Deck *d_deck;
    CardFactory(std::istream &input);

public:
    static CardFactory *getFactory(std::istream &input) {
        static CardFactory *instance = new CardFactory(input);
        return instance;
    };

    Deck *getDeck();
    ~CardFactory();
};

