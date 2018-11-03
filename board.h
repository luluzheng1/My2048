/* Wenlu Zheng
 * comp11
 * hw6
 * game.h
 * game class header
 * signoff by Laney*/
#include "board.h"
#include <unistd.h>
#include <fstream>
#include<iomanip>

#ifndef GAME_H_
#define GAME_H_

class game
{
public:
	//default constructor
	game();
	
	//destructor
	~game();
	
	//notes & clarification for grader
	void foreword();

	//asks user to play game 
	void directions();

	//gives directions on how to play
	bool start_game();
	 
	//reads into the high score file and reports the highest score
	int report_high_score();

	//reads into the high score file and stores all the scores in an array
	int read_score();
	
	//opens file for writing and updates the high score file
	int write_score(int, int);
	
	//adds the points earned from one move to the user's score
	int add_score(int, int&);

	//prints the updated score after every move
	int update_score(int&);
	
	//ends the game
	bool end_game(board &);
	
	//asks if user want to restart	
	bool restart();

private:
	//array to store scores in high_score.txt
	int scores[100];
	//array to store namesin high_score.txt 
	string names[100];
	
	string name;
	string filename;
	static const int ERROR = -1;

	//*fake* loads the game... purely for fun
	void loading();

	//asks for the user's name and stores score and name in an array
	int record_score(int, int);
	
	//sorts the scores from highest to lowest
	void sort_score(int);

	//prints the five highest scores 
	void print_score();
	
};

#endif 

