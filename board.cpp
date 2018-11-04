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