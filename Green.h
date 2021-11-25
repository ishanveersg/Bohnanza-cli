#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Green{
	private:
    color Green;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Green::Card( color c, int coins ){
	Green = c;
	coins = coins;
}

void Green::affiche(){
	cout << Green;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
