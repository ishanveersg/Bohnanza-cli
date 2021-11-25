#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum color { Blue, Chili, Stink, Green, Soy, Black, Red, Garden };

class Chili{
	private:
    color Chili;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Chili::Card( color c, int coins ){
	Chili = c;
	coins = coins;
}

void Chili::affiche(){
	std::cout << Chili;
	std::cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
