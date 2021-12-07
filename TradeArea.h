#include "Card.h"
#include <vector>
#include <list>
#include <iostream>
#include "CardFactory.h"

class TradeArea {
public:
	//Constructeur sans argument
	TradeArea();
	//Destructeur sans argument
	~TradeArea();
	
	TradeArea& operator += (Card*); //ajoute une carte à l’échange mais ne vérifie pas si c'est légal de placer la carte
	bool legal(Card*); //Verification si la carte est legal pour la pile ou pas
	bool empty(); 
	Card* trade(string); //supprime de l’échange une carte du correspondant nom
	int numCards(); //renvoie le nombre courant de cartes en échange
	
	//Pour gere les outils des manipulation des cartes, TradeArea est appele.
	//Ajouter également l'opérateur d'insertion pour insérer toutes les cartes en échange dans
	friend ostream & operator >> (ostream &, TradeArea); //Operateur <<
	//Ajouter également l'opérateur d'insertion pour insérer toutes les cartes en échange dans
	TradeArea(istream&, CardFactory* );
	list<Card*>* cards;
	list<string> cardTypes;
	string getCardType(int);
	
};
