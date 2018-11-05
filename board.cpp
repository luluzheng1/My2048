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