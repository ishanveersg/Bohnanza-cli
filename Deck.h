#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include <vector>
#include <iostream>
#include "CardFactory.h"

class CardFactory;

class Deck : public vector<Card*> {
public:
	// Constructeur par defaut
	
	Deck() = default;
	Deck(istream&, CardFactory*); //Constructeur voir le manuel du projet
	
	Deck(CardFactory*); // Paquet des cartes
	
	Card* draw(); //retourne et supprime la carte supérieure du Deck.
	friend ostream & operator << (ostream &, Deck); //Operateur
};

//Exception si la pile est vide
//Retourner 0 s'il n'y a plus des cartes
class DeckEmpty : public exception
{
	virtual const char* what() const throw()
	{
		return "0";
	}
};



