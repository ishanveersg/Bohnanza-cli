#include "Deck.h"

Card *Deck::draw() {
    Card *card = back();
    pop_back();
    return card;
}

std::ostream &operator<<(std::ostream &output, const Deck &deck) {
    for (int i = 0; i < deck.size(); ++i) {
        output << *deck[i];
    }
    return output;
}


Deck::Deck(std::istream &, CardFactory *) {

}

