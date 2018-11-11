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

//moves the tiles up 
void board::up()
{
	bool again = false;
	for(int row = 1; row < board_size; row++)
	{
		for(int col = 0; col < board_size; col++)
		{
			if(my_board[row][col] != 0 && my_board[row-1][col] == 0)
			{
				my_board[row-1][col] = my_board[row][col];
				my_board[row][col] = 0;
				again = true;
			}
		}
	}
	if(again)
	{
		up();
	}
}

//moves the tiles down
void board::down()
{
	bool again = false;
	for(int row = 0; row < (board_size -1); row++)
	{
		for(int col = 0; col < board_size; col++)
		{
			if(my_board[row][col] != 0 && my_board[row+1][col] == 0)
			{
				my_board[row+1][col] = my_board[row][col];
				my_board[row][col] = 0;
				again = true;
			}
		}
	}
	if(again)
	{
		down();
	}
}
		
//moves the tiles left
void board::left()
{
	bool again = false;
	for(int col = (board_size-1); col > 0; col--)
	{
		for(int row = 0; row < board_size; row++)
		{
			if(my_board[row][col] != 0 && my_board[row][col-1] == 0)
			{
				my_board[row][col-1] = my_board[row][col];
				my_board[row][col] = 0;
				again = true;
			}

		}
	}
	if(again)
	{
		left();
	}
}		

//moves the tiles right
void board::right()
{
	bool again = false;
	for(int col = 0; col < (board_size -1); col++)
	{
		for(int row = 0; row < board_size; row++)
		{
			if(my_board[row][col] != 0 && my_board[row][col+1] == 0)
			{
				my_board[row][col+1] = my_board[row][col];
				my_board[row][col] = 0;
				again = true;
			}

		}
	}
	if(again)
	{
		right();
	}
}	

//moves the tiles up, down, left, or right
void board::update_board()
{	
	switch(move)
	{
	case 'w':
		up();
		break;

	case 's':
		down();
		break;

	case 'a':
		left();
		break;

	case 'd':
		right();
		break;
	}
}

//combines neighboring tiles of the same value after a move
//returns the points earned in that move 
int board::combine()
{
	int curr_points = 0;
	if(move == 'w')
	{
		for(int row = 1; row < board_size; row++)
		{
			for(int col = 0; col < board_size; col++)
			{
				if(my_board[row][col] != 0 && my_board[row][col] == my_board[row-1][col])
				{
					my_board[row-1][col] += my_board[row][col];
					my_board[row][col] = 0;
					curr_points += my_board[row-1][col];
				}
			}
		}
		return curr_points;
	}

	else if(move == 's')
	{
		for(int row = (board_size -1); row > 0; row--)
		{
			for(int col = 0; col < board_size; col++)
			{
				if(my_board[row][col] != 0 && my_board[row][col] == my_board[row-1][col])
				{
					my_board[row][col] += my_board[row-1][col];
					my_board[row-1][col] = 0;
					curr_points += my_board[row][col];
				}
			}
		}
		return curr_points;
	}

	else if(move == 'a')
	{
		for(int col = 1; col < board_size; col++)
		{	
			for(int row = 0; row < board_size; row++)
			{
				if(my_board[row][col] != 0 && my_board[row][col] == my_board[row][col-1])
				{
					my_board[row][col-1] += my_board[row][col];
					my_board[row][col] = 0;
					curr_points += my_board[row][col-1];
				}
			}
		}
		return curr_points;
	}

	else if(move == 'd')
	{
		for(int col = (board_size -1); col >= 0; col--)
		{
			for(int row = 0; row < board_size; row++)
			{
				if(my_board[row][col] != 0 && my_board[row][col] == my_board[row][col+1])
				{
					my_board[row][col+1] += my_board[row][col];
					my_board[row][col] = 0;
					curr_points += my_board[row][col+1];
				}	
			}
		}
		return curr_points;
	}
	return curr_points;
}

//add the tile to a random position(row, col) on the board
//checks if user enters a valid input
//if not, prompt user to reenter
void board::add_tile()
{
	srand(time(NULL));
	if(!all_filled())
	{
		int chance = (rand() % 100) + 1;
		int value = 0;
		if (chance < 10)
		{
			value = 4;
		} 
		else 
			value = 2;

		bool has_value = false;
		while(!has_value)
		{
			int row = rand() % (board_size);
			int col = rand() % (board_size);
			if(my_board[row][col] == 0)
			{
				my_board[row][col] = value;
				has_value = true;
			}
		}
	} 
}

//checks if all tiles are filled
//returns true if all tiles have a value other than 0
bool board::all_filled()
{
	for (int row = 0; row < board_size; ++row)
	{
		for(int col = 0; col < board_size; ++ col)
		{
			if (my_board[row][col] == 0)
				return false;
		}
	}
	return true;
}

//checks if neighboring tiles have the same value
//returns false if no neighboring tiles are of the same value
bool board::same_value()
{
	for(int row = 0; row < board_size; row++)
		for(int col = 0; col < (board_size - 1); col++)
		{
			if(my_board[row][col] == my_board[row][col+1])
				return true;
		}
	for(int row = 0; row < (board_size -1); row++)
		for(int col = 0; col < board_size; col++)
		{
			if(my_board[row][col] == my_board[row+1][col])
				return true;
		}
	return false;
}
	
//destructor
board::~board()
{
	for (int row = 0; row < board_size; ++row)
	{
		delete [] my_board[row];
	}
	delete [] my_board;
}
