#pragma once
#include "CardFactory.h"

class Hand : public vector<Card*> {
private:


public:
	Hand() = default;						//default constructor
	Hand& operator+=(Card*);				//a joute une carte derricre la dernicre carte de la main.
	Card* play();							//renvoie et supprime la premicre carte de la main du joueur .
	Card* top();							//renvoie mais ne supprime pas la premicre carte de la main du joueur.
	Card* operator[](int);					//renvoie et supprime une carte r une position donnée.
	Hand(istream&, CardFactory*);		//constructeur qui accepte fichier
	friend ostream & operator << (ostream &, Hand);
};
