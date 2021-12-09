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
        //Populate the deck with the specified cards
        for (size_t i = 0; i < 104; i++) {
            if (i < 20) {
                d_deck->push_back(new Quartz());
            } else if (i < 38) {
                d_deck->push_back(new Hematite());
            } else if (i < 54) {
                d_deck->push_back(new Obsidian());
            } else if (i < 68) {
                d_deck->push_back(new Malachite());
            } else if (i < 80) {
                d_deck->push_back(new Turquoise());
            } else if (i < 90) {
                d_deck->push_back(new Ruby());
            } else if (i < 98) {
                d_deck->push_back(new Amethyst());
            } else {
                d_deck->push_back(new Emerald());
            }
        }
        //Only shuffle when a new deck is made. If we're loading from a file we want to persist the deck
        std::random_shuffle(d_deck->begin(), d_deck->end());
    }
}