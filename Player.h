#include <string>
#include <iostream>
#include "CardFactory.h"
#include <vector>
#include <exception>
#include "Chain.h"
#include "Hand.h"

using namespace std;

class Player {
	int maxNumChains;
	chainElement chains;
	Hand *hand;
	string name;
	int numCoins;

public:
	ChainBase& operator[](int i);		
	void buyThirdChain();			
	void printHand(ostream&, bool); 
	void print(ostream&);
	Player(std::string&);			
	string getName();				
	int getNumCoins();			
	Player& operator+=(int);
	Player(istream&, CardFactory*); 
	int getMaxNumChains();			
	int getNumChains();			

private:
	void addChain(char);
};

class No_chain : public exception{
	virtual const char* what() const throw()	{
		return "0";
	}
};

class ChainContainer {
	int n;
	ChainBase* chain1;
	ChainBase* chain2;

public:
	ChainContainer() {
		n = 0;
		chain1 = NULL;
		chain2 = NULL;
		
	};

	ChainBase & ChainContainer:: operator[](int i) {
		if (0 <= i && i < 2) {
			if (i == 0){
				return *chain1;
			}				
			if (i == 1){
				return *chain2;
			}
		}	
		else
			throw No_chain();
	};

	ChainBase& back() {
		
		return (*this)[n];
	};

};




class NotEnoughCoins : public exception{
	
	virtual const char* what() const throw(){
		return "0";
	}

	friend ostream & operator << (ostream & outp, NotEnoughCoins Not_coins) {
		outp << Not_coins.what();
		return outp;
	}

};
