#include "Hand.h"
#include <string>
#include <iostream>


//ajoute une carte a la fin de hand
Hand& Hand ::operator+=(Card*cardToAdd) {  
	(*this).insert(begin(), cardToAdd);
	return *this;

}

//renvoie la premier carte de hand
//Supprime la carte supprimE
Card* Hand :: play() {

	Card* temp = (*this).back();
	(*this).pop_back();
	return temp;

}

//renvoie la premiere carte de hand
Card* Hand ::top() {
	return (*this).back();
}

//Supprime une carte a 'position'
Card* Hand ::operator[](int position) {
	Card* temp = (*this).at((*this).size() - position);
	(*this).erase( (*this).begin() + ((*this).size()-position) );
	return temp;
}


Hand:: Hand(std::istream& x1, CardFactory* cf) {
	char cardType[256];
	x1.getline(cardType, 256);
	x1.getline(cardType, 256);

	int cnt = 0;
	while (cardType[cnt] != NULL) {
		cnt++;
	}
	cnt--;
	for (int i = cnt; i >= 0; i--) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);
	}

}	

ostream & operator<<(ostream & out, Hand _hand){
	
	// TODO: make sure cards are in order
	for (vector<Card*>::reverse_iterator it = _hand.rbegin(); it != _hand.rend(); it++) {
		out << (*it);
	}
	return out;
}
