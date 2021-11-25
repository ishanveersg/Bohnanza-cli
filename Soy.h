#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Soy{
	private:
    color Soy;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Soy::Card( color c, int coins ){
	Soy = c;
	coins = coins;
}

void Soy::affiche(){
	cout << Soy;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
