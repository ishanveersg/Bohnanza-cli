#include <iostream>
#include <string>
#include <cassert>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

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

