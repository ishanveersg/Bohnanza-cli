#include "Player.h"

Player:: Player(string &playerName) {	
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	hand = new Hand();
}


string Player :: getName() {
	return name;
}

int Player:: getNumCoins() {
	return numCoins;
}

Player& Player:: operator +=(int i) {
	numCoins = numCoins + i;
	return(*this);
}

Player & Player::operator+=(Card *card)
{
	*hand += card;
	return *this;
}

int Player:: getMaxNumChains() {
	return maxNumChains;
}

int Player::getNumChains() {
	return chains.size();

}


 ChainBase& Player:: operator[](int i) {	
	 if (i < getNumChains())
		 return chains[i];
	 else
		 throw ChainDoesntExist();
}


void Player:: buyThirdChain() {
	if (numCoins < 3)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 3;
																
		maxNumChains++;
	}

}

void Player::printHand(ostream& out, bool notTopCard) {
	if (notTopCard) {
		out << *hand;
	}
	else {
		out << hand->top();
	}
																					

}


Player:: Player(istream& inp, CardFactory* card_factory) {
	getline(in,name, '\t');
	
	inp >> numCoins;
	inp >> maxNumChains;
	hand = new Hand(inp, card_factory);
	char type;
	int size;
	string chainInfo;
	string tmp;
	for (int i = 0; i < 3; i++) {
		getline(inp, chainInfo);
		if (chainInfo.compare("NULL") != 0) {
			
			type = type_.at(0);
			size = x1(type_.substr(2).c_str());
			
			addChain(type);
			for (int i = 0; i < size; i++) {
				addToChain(card_factory->getCard(type));
			}
		}
	}
}

void Player::addChain(char type){ //Creation des cartes 
//Via cardFactory
//Les lettres sont dans les .cpp de chaque nom de couleur
	if (type == 'B') {
		ChainBase* newChain = new Chain<Blue>;
		chains.addChain(newChain);}
		
	else if (type == 'C') {
		ChainBase* newChain = new Chain<Chili>;
		chains.addChain(newChain);}
		
	else if (type == 'S') {
		ChainBase* newChain = new Chain<Stink>;
		chains.addChain(newChain);}
		
	else if (type == 'G') {
		ChainBase* newChain = new Chain<Green>;
		chains.addChain(newChain);}
		
	else if (type == 's') {
		ChainBase* newChain = new Chain<Soy>;
		chains.addChain(newChain);}
		
	else if (type == 'b') {
		ChainBase* newChain = new Chain<Black>;
		chains.addChain(newChain);}
		
	else if (type == 'R') {
		ChainBase* newChain = new Chain<Red>;
		chains.addChain(newChain);}
		
	else if (type == 'g') {
		ChainBase* newChain = new Chain<Garden>;
		chains.addChain(newChain);}
}

//retourne les coins
ostream & operator<<(ostream & outp, Player player_){
	out << player_.getName() << '\t' << player_.getNumCoins() << " coins\n";
	for (int i = 0; i < player_.getNumChains(); i++)
	
		outp << player_[i] << "\n";
	return outp;
}

//Affiche les cartes
void Player::print(ostream & outp){	

	outp << getName() << '\t' << getNumCoins() << ' ' << getMaxNumChains() << "\n";
	
	outp << *hand << "\n";
	
	for (int i = 0; i < 3; i++){
		
		if (i < getNumChains())
		
			outp << chains[i].getType().at(0) << " " << chains[i].getSize() << "\n";
			
		else
			outp << "NULL" << "\n";
	}
		
}
