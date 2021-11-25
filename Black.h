#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Black{
	private:
    color Black;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Black::Card( color c, int coins ){
	Black = c;
	coins = coins;
}

void Black::affiche(){
	cout << Black;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
