#include "CardFactory.h"

CardFactory::CardFactory()
{
	for (size_t noBlue = 0; noBlue < 20; ++noBlue) {
		deck.push_back(new Blue());
	}
	for (size_t noChili = 0; noChili < 18; ++noChili) {
		deck.push_back(new Chili());
	}
	for (size_t noStink = 0; noStink < 16; ++noStink) {
		deck.push_back(new Stink());
	}
	for (size_t noGreen = 0; noGreen < 14; ++noGreen) {
		deck.push_back(new Green());
	}
	for (size_t noSoy = 0; noSoy < 12; ++noSoy) {
		deck.push_back(new Soy());
	}
	for (size_t noBlack = 0; noBlack < 10; ++noBlack) {
		deck.push_back(new Black());
	}
	for (size_t noRed = 0; noRed < 8; ++noRed) {
		deck.push_back(new Red());
	}
	for (size_t noGarden = 0; noGarden < 6; ++noGarden) {
		deck.push_back(new Garden());
	}
	deck.shrink_to_fit();

	cardReturned.fill(false);
}

Deck CardFactory::getDeck()
{
	// Shuffle the deck and return it
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 g(seed);
	std::shuffle(deck.begin(), deck.end(), g);
	return deck;
}

Card* CardFactory::getCard(const char& ch)
{
	Card* retCard = nullptr;
	for (int i = 0; i < 104; ++i) {
		// Only return the card that's not been returned before
		if (!cardReturned[i] && deck[i]->getName()[0] == ch) {
			retCard = deck[i];  cardReturned[i] = true;
			break;
		}
	}
	return retCard;
}

CardFactory::~CardFactory() {
	for (auto &c : deck)  delete c;
}

CardFactory* CardFactory::getCardFactory() {
	static CardFactory cFactory;
	return &cFactory;
}