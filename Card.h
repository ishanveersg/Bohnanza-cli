#ifndef Card_h
#define Card_h
#include <iostream>
#include <string>
#include <cassert>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

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

class Card { //Carte
public:
	virtual int getCardsPerCoin(int) = 0; //FOnction 1  retourne nombre des coins
	virtual string getName() = 0; // Fonction 2 retourne le nom de la carte
	friend ostream& operator << (ostream& out, const Card& MaCarte) {
		MaCarte.print(out);
		return out;
	};
	//Constructeur de Card
	friend ostream& operator << (ostream& out, const Card* MaCarte) { 
		out << (*MaCarte);
		return out;
	};
protected:
	//Inserer un nouveu caractere carte en haut
	virtual void print(ostream&) const = 0;
};

