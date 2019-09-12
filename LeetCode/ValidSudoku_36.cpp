#include "pch.h"
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	
	
	for (int ri = 0; ri < 9; ri++)
	{
		std::set<char> rowkey;
		std::set<char> columnkey;
		std::set<char> unitkey;

		int rr = ri / 3;
		int cc = ri % 3;

		for (int rj = 0; rj < 9; rj++)
		{
			char rkey = board[ri][rj];
			if (rkey != '.')
			{
				if (rowkey.find(rkey) != rowkey.end())
				{
					return false;
				}
				rowkey.insert(rkey);
			}

			char ckey = board[rj][ri];
			if (ckey != '.')
			{
				if (columnkey.find(ckey) != columnkey.end())
				{
					return false;
				}
				columnkey.insert(ckey);
			}


			int r = rj / 3;
			int c = rj % 3;

			r = rr * 3 + r;
			c = cc * 3 + c;

			char ukey = board[r][c];

			if (ukey != '.')
			{
				if (unitkey.find(ukey) != unitkey.end())
				{
					return false;
				}
				unitkey.insert(ukey);
			}
		}
	}

	return true;
}


int getUnitSequence(int r, int c)
{
	if (r < 3)
	{
		if (c < 3)
		{
			return 0;
		}

		if (c >= 3 && c <= 5)
		{
			return 1;
		}
		return 2;
	}

	if (r >= 3 && r <= 5)
	{
		if (c < 3)
		{
			return 3;
		}
		if (c >= 3 && c <= 5)
		{
			return 4;
		}
		return 5;
	}

	if (c < 3)
	{
		return 6;
	}
	if (c >= 3 && c <= 5)
	{
		return 7;
	}
	return 8;

}

bool isValidSudoku_v2(vector<vector<char>>& board) {

	char tt[3][9][9] = {};	

	for (int ri = 0; ri < 9; ri++)
	{		

		for (int rj = 0; rj < 9; rj++)
		{
			char key = board[ri][rj];

			if (key == '.') continue;


			int num = key - '1';

			if (tt[0][ri][num] > 0)
			{
				return false;
			}
			tt[0][ri][num] = 1;

			if (tt[1][rj][num] > 0)
			{
				return false;
			}
			tt[1][rj][num] = 1;

			int us =getUnitSequence(ri, rj); // (ri / 3) * 3 + rj / 3; //

			if (tt[2][us][num] > 0)
			{
				return false;
			}
			tt[2][us][num] = 1;
		}
	}

	return true;
}

TEST(ValidSudoku, MustTrue) {

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
  EXPECT_TRUE(isValidSudoku_v2(board));
}

TEST(ValidSudoku, MustFalse) {

	vector<vector<char>> board = {
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	EXPECT_FALSE(isValidSudoku_v2(board));
}


TEST(ValidSudoku, MustTrueRet) {

	vector<vector<char>> board =
	{ 
	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	EXPECT_TRUE(isValidSudoku_v2(board));
}