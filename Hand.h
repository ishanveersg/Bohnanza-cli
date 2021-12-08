#include "CardFactory.h"
#include <vector>

class Hand : public vector<Card*> {
public:
	Hand() = default; // constructeur par defaut
	Hand& operator+=(Card*);
	//renvoie et supprime la premicre carte de la main du joueur .
	Card* play();							
	Card* top();	
	Card* operator[](int);
	Hand(istream&, CardFactory*);		//constructeur 1
	friend ostream & operator << (ostream &, Hand);		// constructeur 2
};
