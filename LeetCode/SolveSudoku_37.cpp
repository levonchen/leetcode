#include "pch.h"

#include <vector>
using namespace std;

//#include "ValidSudoku_36.cpp"

//extern int getUnitSequence(int r, int c);
extern bool isValidSudoku_v2(vector<vector<char>>& board);

int rows[9];
int cols[9];
int cubes[9];

int getCube(int row, int col)
{
	return (row / 3) * 3 + col / 3;
}

void addNumber(int row, int col, int cube, vector<vector<char>>& board, int number)
{
	char v = (char)('0' + number);
	int num = 1 << number;

	rows[row] |= num;
	cols[col] |= num;
	cubes[cube] |= num;

	board[row][col] = v;
}

void removeNumber(int row, int col, int cube, vector<vector<char>>& board, int number)
{
	int num = 1 << number;
	rows[row] ^= num;
	cols[col] ^= num;
	cubes[cube] ^= num;

	board[row][col] = '.';
}

bool isValid(vector<vector<char>>& board, int row, int column, int cube, int d)
{
	
	int check = ((rows[row] >> d) & 1) + ((cols[column] >> d) & 1) + ((cubes[cube] >> d) & 1);
	if (check == 0) {		
		return true;
	}
	return false;
}

bool solve(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9;j++)
		{
			if (board[i][j] != '.')
			{
				continue;
			}

			int cube = getCube(i, j);

			for (int start = 1; start <= 9; start++)
			{
				if (isValid(board, i, j, cube,start))
				{					

					addNumber(i, j, cube, board, start);

					if (solve(board))
					{
						return true;
					}
					else
					{
						removeNumber(i, j, cube, board, start);
					}
				}
			}

			return false;
		}
	}

	return true;
}




void solveSudoku(vector<vector<char>>& board) {

	for (int r = 0; r < 9; ++r)
	{
		for (int c = 0; c < 9; ++c)
		{
			if (board[r][c] != '.')
			{
				int cube = getCube(r, c);

				int num = board[r][c] - '0';
				addNumber(r, c, cube, board, num);
			}
		}
	}

	solve(board);
}




TEST(SolveSudoku, func1) {

	vector<vector<char>> board = {
		{ '5','3','.','.','7','.','.','.','.' },
	{ '6','.','.','1','9','5','.','.','.' },
	{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },
	{ '4','.','.','8','.','3','.','.','1' },
	{ '7','.','.','.','2','.','.','.','6' },
	{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },
	{ '.','.','.','.','8','.','.','7','9' }
	};

	solveSudoku(board);

	auto ret = isValidSudoku_v2(board);

	EXPECT_TRUE(ret);
}