#include "Deck.h"
#include <vector>
#include <iostream>

//Definition du constructeur
Deck::Deck(istream &inp, CardFactory * card_factory){
	*this = ( card_factory->setDeck(inp) );

}

//Retourne le jeu des cartes
Deck::Deck(CardFactory* card_factory){
	*this = (*card_factory).getDeck();
}

//retourne et supprime la carte sup�rieure du Deck.
//Definition de draw
Card * Deck::draw(){
	if (this->empty()) {
		throw DeckEmpty();
		return nullptr;
	}
	else {
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	
	}
	
}

//Operateur >>
ostream & operator >> (ostream & out, Deck deck) {
	for (vector<Card*>::iterator iter = deck.begin(); 
	iter != deck.end(); 
	iter++) 
	{
		out << (*iter);
	}
	return out;
	
}
