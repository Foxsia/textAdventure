#include <iostream>

using namespace std;

int chooseLvl() {
	int level;
	cout << "Choose a level (1-3):\n";
	cin >> level;
	cin.ignore();
	return level;
}