#include "CardFactory.h"

Deck *CardFactory::getDeck() {
    return d_deck;
}

CardFactory::~CardFactory() {
    delete d_deck;
}

CardFactory::CardFactory(std::istream &input) {
    if (d_deck == nullptr) {
        d_deck = new Deck(input, this);
    }
    if (d_deck->empty()) {
        //Populate the deck 
        for (size_t i = 0; i < 104; i++) {
            if (i < 20) {
                d_deck->push_back(new Blue());
            } else if (i < 38) {
                d_deck->push_back(new Chili());
            } else if (i < 54) {
                d_deck->push_back(new Stink());
            } else if (i < 68) {
                d_deck->push_back(new Green());
            } else if (i < 80) {
                d_deck->push_back(new Soy());
            } else if (i < 90) {
                d_deck->push_back(new Black());
            } else if (i < 98) {
                d_deck->push_back(new Red());
            } else {
                d_deck->push_back(new Garden());
            }
        }
        std::random_shuffle(d_deck->begin(), d_deck->end());
    }
}