#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Garden{
	private:
    color Garden;
    int coins;
	public:
	Card(color,int);
	void affiche();
};

Garden::Card( color c, int coins ){
	Garden = c;
	coins = coins;
}

void Garden::affiche(){
	cout << Garden;
	cout << coins;
}

int main(int argc, char** argv) {
	return 0;
}
