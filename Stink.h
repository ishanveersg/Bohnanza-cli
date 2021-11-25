#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Stink{
	private:
    color Stink;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Stink::Card( color c, int coins ){
	Stink = c;
	coins = coins;
}

void Stink::affiche(){
	cout << Stink;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
