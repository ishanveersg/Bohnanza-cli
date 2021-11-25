#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Red{
	private:
    color Red;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Red::Card( color c, int coins ){
	Red = c;
	coins = coins;
}

void Red::affiche(){
	cout << Red;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
