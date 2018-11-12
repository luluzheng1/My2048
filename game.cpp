#include "game.h"

//default constructor
game::game()
{
	filename = "high_score.txt";
}

//destructor
game::~game()
{

}

//asks user to play game 
//returns true if user enters y
//returns false if user enters n
//calls itself if user input is invalid
bool game::start_game()
{
	char start;
	cout << "\n\n";
	cout << "\t\tDo you want to start a game?\n";
	cout << "\n";
	cout << "\t\tEnter y or n\n";
	cin >> start;
	if (start == 'y')
		return true;
	else if (start == 'n')
		return false;
	else start_game();
	return false;
}

