#pragma once
#include "CardFactory.h"

class Hand : public vector<Card*> {
private:


public:
	Hand() = default;						//default constructor
	Hand& operator+=(Card*);				//a joute une carte derri�re la derni�re carte de la main.
	Card* play();							//renvoie et supprime la premi�re carte de la main du joueur .
	Card* top();							//renvoie mais ne supprime pas la premi�re carte de la main du joueur.
	Card* operator[](int);					//renvoie et supprime une carte � une position donn�e.
	Hand(istream&, CardFactory*);		//constructeur qui accepte fichier
	friend ostream & operator << (ostream &, Hand);
};


