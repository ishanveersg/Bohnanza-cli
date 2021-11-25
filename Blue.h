#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum color { Blue, Chili, Stink, Green, Soy, Black, Red, Garden };

class Blue{
	private:
    color Blue;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Blue::Card( color c, int coins ){
	Blue = c;
	coins = coins;
}

void Blue::affiche(){
	std::cout << Blue;
	std::cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
