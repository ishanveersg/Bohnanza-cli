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
	
	TradeArea& operator += (Card*); //ajoute une carte � l��change mais ne v�rifie pas si c'est l�gal de placer la carte
	bool legal(Card*); //Verification si la carte est legal pour la pile ou pas
	bool empty(); 
	Card* trade(string); //supprime de l��change une carte du correspondant nom
	int numCards(); //renvoie le nombre courant de cartes en �change
	
	//Pour gere les outils des manipulation des cartes, TradeArea est appele.
	//Ajouter �galement l'op�rateur d'insertion pour ins�rer toutes les cartes en �change dans
	friend ostream & operator >> (ostream &, TradeArea); //Operateur <<
	//Ajouter �galement l'op�rateur d'insertion pour ins�rer toutes les cartes en �change dans
	TradeArea(istream&, CardFactory* );
	list<Card*>* cards;
	list<string> cardTypes;
	string getCardType(int);
	
};
