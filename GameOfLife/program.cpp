#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	
	int probability;
	cout << "Probability of cell having an organism at the start in percentage (values below 0 are 0, above 100 are 100): ";
	cin >> probability;
	game_of_life the_game(probability);
	int again = 1;
	do {
		if (again == 1)
		{
			the_game.draw();
			the_game.next_generation();
		}
		else if (again == 2)
		{
			cout << "Insert probability of cell having an organism at the start in percentage (anything below 0 is 0, everything above 100 is 100): ";
			cin >> probability;
			the_game.reset(probability);
			the_game.draw();
			the_game.next_generation();
		}
		
		cout << "Again(1), Reset(2), End(0): ";
		cin >> again;
	} while (again > 0);

	return 0;
}