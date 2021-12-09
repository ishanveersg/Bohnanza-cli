#include "TradeArea.h" 
#include <iostream>
#include <vector>


 //Modele de Cont 
template <typename Base>
bool contains(Base const& MaCarte1, typename Base::const_reference val1) {
	return std::find(MaCarte1.begin(), MaCarte1.end(), val1) != MaCarte1.end();
}

template<class Iterateur, class T>
Iterateur findName(Iterateur premier, Iterateur suivant, const T& val){
	while (premier != suivant ) {
		if ((*premier)->getName().compare(val) == 0){
			return premier;
		} 
		++first;
	}
	return last;
}


bool containsName(list<Card*> const& MaCarte1, string& val1) {
	
	list<Card*>::const_iterator first = MaCarte1.begin();
	list<Card*>::const_iterator last = MaCarte1.end();
	
	while (first != last) {
		
		if ((*first)->getName().compare(val1) == 0) 
		return true;
		
		++first;
	}
	
	return false;

}

TradeArea::TradeArea(){
	
	cards = new list<Card*>;
	cardTypes = list<string>();
}

TradeArea & TradeArea::operator+=(Card *card){
	
	(*cards).insert((*cards).begin(), card);
	
	if (!contains(cardTypes, card->getName())) {						
		cardTypes.emplace_front(card->getName());

	}

	return *this;
}

bool TradeArea::legal(Card *card){
	return (cards->size() < 3 || contains(cardTypes, card->getName()));
}

Card * TradeArea::trade(string name){
	
	if (empty())
	
		return nullptr;
	list<Card*>::iterator iterateur__ = cards->begin();
	
	while (iterateur__ != cards->end()) {
		if (name.compare((**iterateur__).getName()) == 0) {
			Card* temp = *iterateur__;
			cards->erase(iterateur__);
			if (!containsName(*cards, name)) {					
				cardTypes.remove(name);
			}
			return temp;
		}
		iterateur__ = iterateur__++ ;
	}
	
	return nullptr;
}

int TradeArea::numCards(){
	return cards->size();
}

TradeArea::TradeArea(istream & in, CardFactory *cf){
	
	cards = new list<Card*>;
	cardTypes = list<string>();
	char cardType[256];
	in.getline(cardType, 256);
	int cnt = 0;
	while (cardType[cnt] != NULL) {
		cnt++;
	}
	cnt--;
	for (int i = cnt ; i >= 0; i--) {
			Card* cardToAdd = ((*cf).getCard(cardType[i]));
			(*this) += cardToAdd;
		}
}

