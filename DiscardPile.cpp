#include "DiscardPile.h"


DiscardPile::DiscardPile()
{
	if (DiscardPile == 0){
		return 0;
	}
	else{
		return 1;
	}
}

DiscardPile::~DiscardPile();

//Jetter une carte dans la pile
DiscardPile & DiscardPile::operator+=(Card *card)
{
	(*this).push_back(card);
	return *this;
}

//renvoie et supprime la carte supérieure de la pile au rebut
Card * DiscardPile::pickUp()
{
	if (this->empty()) { //SI le jeu de carte est vide
		throw domain_error("Pas de carte dans la file");
		return nullptr;
	}
	else { //Si la pile n'est pas vide
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	}
}
//renvoie mais ne supprime pas la carte supérieure de la pile au rebut
/*
Card * DiscardPile::top()
{
	return Card.begein();
}
 */
Card * DiscardPile::top(){
	return this->back();
}

// Si la pile est vide
/* 
bool DiscardPile::isEmpty()
{
	if (Card->size() == 0)
		return true;
	else {
		return false;
	}
}
 */
bool DiscardPile::isEmpty(){
	if ((*this).size() == 0)
		return true;
	else {
		return false;
	}
}

//pour insérer toutes les cartes de DiscardPile dans std::ostream
void DiscardPile::print(ostream & out){
	if (!isEmpty()) {
		for (vector<Card*>::iterator it = this->begin(); it != this->end(); it++) {
			out << (**it);
		}
	}
	/*else
		out << "Discard pile is empty";*/
}

//possède un constructeur qui accepte un flux istream et construit un objet de type DiscardPile à partir du fichier
DiscardPile::DiscardPile(istream & inp, CardFactory * carte_factory){
	char cardType[256];
	inp.getline(cardType, 256);
	int compteur = 0;
	while (cardType[cnt] != NULL) {
		compteur = compteur + 1 ;
	}
	compteur = (compteur + 1) - 2;
	for (int i = compteur ; i >= 0; i--) {
		Card* cardToAdd = ((*carte_factory).getCard(cardType[i]));
		(*this).push_back(cardToAdd);
	}

}

ostream & operator<<(ostream & out, DiscardPile discard_pile){
	if (!discard_pile.isEmpty()) { // ou discard_pile -> a verifier
		out << discard_pile.back();
	}
	
	return out;
}

