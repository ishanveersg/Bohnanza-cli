#include "Card.h"
#include <vector>
#include "CardFactory.h"


class Premier_chaine {

public:
	/* 
	friend ostream & operator << (ostream & o, const Premier_chaine& cb) { //Test de constructeur
		cb.cout(o);
		return o;
	};
	*/
	virtual bool legal(Card*) = 0;
	virtual int sell() = 0;
	virtual int getSize() = 0; // Taille
	virtual string getType() = 0; //Type
	
	
	friend ostream & operator << (ostream & S, const Premier_chaine& Machaine) { //Constructeur des nouvelles cartes 
	// MaChaine == Chain_Base
		Machaine.cout(S);
		return S;
	};
	
	Premier_chaine& operator+= (Card* card) { // Surdefinition de l'operateur +=
		this->addCard(card);
		return *this;
	};
	/* 
	Premier_chaine* operator += (Card* card) { 
		this.addCard(card);
		return *addCard(card);
	};
	*/
	
	//Fonctions protege
protected:
	virtual void addCard(Card*) = 0; //Ajoute une carte
	virtual void print(ostream&) const = 0; // Sortie de la carte par Ostream
	
};


template <class T> class Chain : public Premier_chaine, public vector<T*> {
public:
	// default constructor
	Chain();
	Chain(istream&, CardFactory*);
	bool legal(Card*);						//Verifie si on peux ajouter une nouvelle carte
	Chain<T>& operator+= (Card* card);
	int sell();
	friend ostream & operator << (ostream & sortie, Chain<T> carte) {  //Constructeur fonction amie
		sortie << carte.getType() << '\t';

		if (carte.getSize() => 0) { // if(Card.getSize() <= 0)
			
			for (int i = 0; i< carte.getSize(); i++)
			
				sortie << carte.getType().at(0);
		}
		
		return sortie;
	};
	
	void addCard(Card* ); //Ajouter une nouvelle carte
	int getSize();
	string getType(); //Type de carte
	
protected:
	string type;
	void print(ostream& outp) const {
		outp << (*this);
	};
};

//Exception du type de carte
class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		
		return "La carte est incorrecte";
	}
};

//Modele pour retourner le nom d'une carte
template<class T>
inline Chain<T>::Chain()
{
	T temp;
	type = temp.getName();
}

//COmparaison des cartes si c'est legal
template<class T>
bool Chain<T>::legal(Card *card)
{
	return (type.compare((*card).getName()) == 0);
}

//Modele pour ajouter une carte
template<class T>
Chain<T>::Chain(istream & inpu , CardFactory * cartefactory)
{

	string chainTitle;
	getline(inpu, chainTitle, '\t');
	char type[256];
	inpu.getline(type, 256);

	while (type != NULL) {
		if (type != ' ') {
			Card* cardToAdd = ((*cartefactory).getCard(type));
			(*this).push_back(cardToAdd);
		}
		i++;
	}

}

//Modele pour gerer l'exception
template<class T>
Chain<T>& Chain<T>::operator+=(Card *card)
{
	
	if (typeid(card)){
		T* temporaire = new T();
		this->push_back(temporaire);
	}
	else {
		throw IllegalType();
	}

	return *this;
}

//Modele de sell
template<class T>
int Chain<T>::sell()
{
	T temporaire;
	for (int x1 = 4; x1 > 0; x1--) {
		
		if (this->getSize() >= temporaire.getCardsPerCoin(x1)) {
			
			return x1;

		}
	}

	return 0;
}

//Modele de la chaine
template<class T>
void Chain<T>::addCard(Card * card)
{
	(*this) += card;
}

//MOdele pour retourner le type
template<class T>
inline string Chain<T>::getType()
{
	return type;
}

//MOdele pour retourner la taille
template<class T>
inline int Chain<T>::getSize()
{
	return this->size();
}




