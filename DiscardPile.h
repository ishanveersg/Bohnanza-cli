#include "CardFactory.h"
#include <vector>
#include <iostream>

//Pour gerer la pile des cartes
class DiscardPile {

private: vector<Card*> d_cards;

public:
	DiscardPile(); //COnstructeur sans argument
	~DiscardPile(); //Desctructeur
	DiscardPile& operator+= (Card*); //Jetter une carte dans la pile
	
	Card* pickUp(); //renvoie et supprime la carte sup�rieure de la pile au rebut
	Card* top(); //renvoie mais ne supprime pas la carte sup�rieure de la pile au rebut
	
	void print(ostream&); //pour ins�rer toutes les cartes de DiscardPile dans std::ostream
	
	friend ostream & operator << (ostream &, DiscardPile); //Operateur
	DiscardPile(istream&, CardFactory*); //poss�de un constructeur qui accepte un flux istream et construit un objet de type DiscardPile � partir du fichier
	
	bool isEmpty(); //Verifie s'il y a des cartes ou pas
	
};
