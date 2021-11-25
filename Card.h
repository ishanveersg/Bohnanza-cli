#include <iostream>
using namespace std;
#include <cassert> //for assert()

enum color { Blue, Chili, Stink, Green, Soy, Black, Red, Garden };

class Card{
	private:
		color c;
	public:
		virtual int getCardsPerCoin(int coins) = 0;
		virtual string getName() = 0;
		virtual void print(ostream& out) = 0;
};

/*

class Card {
public:
	Card(color c = Blue, int v = 1);
	virtual int getCardsPerCoin(int coins) = 0;
	virtual string getName() =0;
	virtual void print(ostream& out) = 0;
    
private:
    color col;
    int val;
};

/*Constructor*//*
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}
*/
