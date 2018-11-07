/* board class definition */

#include "board.h"
#include<ctime>
#include<cstdlib>

//default constructor
board::board()
{
	board_size = 0;
	my_board = NULL;
	move = 'n';
}

//copy constructor
board::board(board &h)
{
	board_size = h.board_size;
	my_board = new int*[board_size];
	for(int i = 0; i < board_size; i++)
	{
		my_board[i] = h.my_board[i];
	}
}

//assignment operator
board & board::operator = (const board &h)
{
	board_size = h.board_size;
	my_board = new int*[board_size];
	for(int i = 0; i < board_size; i++)
	{
		my_board[i] = h.my_board[i];
	}
	return *this;
}

//prompts the user for dimension of board
void board::get_board_size()
{
	 cout << "\t\tWhat board size would you like?\n";
	 cin >> board_size;

	 //dynamic allocation
	 my_board = new int* [board_size];
	 for (int i = 0; i < board_size; ++i)
	 {
	 	my_board[i] = new int[board_size];
	 }
	 	
	 //fill
	 for (int row = 0; row < board_size; ++row)
	 	for(int col = 0; col < board_size; ++col)
	 		my_board[row][col] = 0;
}

//determines the position and value of two starting tiles
void board::start_tiles()
{
	my_board[0][0] = 2;
	my_board[1][1] = 2;
	print_board(); 
}

//prompt the user for dimension of board
//prints board to user
void board::print_board()
{
		for (int col = 0; col < board_size; ++col)
		{
			for (int row = 0; row < board_size; ++row)
			{
				if (my_board[col][row] == 0)	
					cout << "\tx\t";
				else 
					cout << "\t" << my_board[col][row] << "\t";
				if ( row % board_size == board_size -1)
					cout << "\n\n";
			}
		}
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//asks user to enter a move
//returns the move (w, s, d, a, h, or q)
//any other letter is an invalid move
//the function calls itself if the letter is invalid
char board::get_move()
{	
	bool invalid = false;
		cout << "\t\tEnter your move:\n";
		//allows user to play without pressing the return key
		system("stty raw");
		cin >> move;
		cout << endl << endl;
		if (move != 'w' && move != 's' && move != 'd' && move != 'a' && move != 'q' && move != 'h')
		{
			cout << "\t\tinvalid, move should be w, s, d, a, h, q, or x\n";
			invalid = true;
		}
		system("stty cooked");
		cout << endl;
		if(invalid)
			get_move();
		return move;
}			