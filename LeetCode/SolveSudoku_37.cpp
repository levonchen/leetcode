#include "pch.h"

#include <vector>
using namespace std;

//#include "ValidSudoku_36.cpp"

extern int getUnitSequence(int r, int c);
extern bool isValidSudoku_v2(vector<vector<char>>& board);

//int getUnitSequence(int r, int c)
//{
//	if (r < 3)
//	{
//		if (c < 3)
//		{
//			return 0;
//		}
//
//		if (c >= 3 && c <= 5)
//		{
//			return 1;
//		}
//		return 2;
//	}
//
//	if (r >= 3 && r <= 5)
//	{
//		if (c < 3)
//		{
//			return 3;
//		}
//		if (c >= 3 && c <= 5)
//		{
//			return 4;
//		}
//		return 5;
//	}
//
//	if (c < 3)
//	{
//		return 6;
//	}
//	if (c >= 3 && c <= 5)
//	{
//		return 7;
//	}
//	return 8;
//
//}

bool isValid(vector<vector<char>>& board, int row, int column, char value)
{

	int unit = getUnitSequence(row, column);

	for (int index = 0; index < 9; index++)
	{
		if (board[row][index] == value)
			return false;

		if (board[index][column] == value)
			return false;

		int uR = 3 * (unit / 3) + index / 3;
		int uC = 3 * (unit % 3) + index % 3;


		if (board[uR][uC] == value)
			return false;
	}

	return true;
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

			for (char start = '1'; start <= '9'; start++)
			{
				if (isValid(board, i, j, start))
				{
					board[i][j] = start;

					if (solve(board))
					{
						return true;
					}
					else
					{
						board[i][j] = '.';
					}
				}
			}

			return false;
		}
	}

	return true;
}




void solveSudoku(vector<vector<char>>& board) {

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