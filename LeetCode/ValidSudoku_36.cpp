#include "pch.h"
#include <vector>
#include <unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	
	
	for (int ri = 0; ri < 9; ri++)
	{
		std::unordered_map<char, bool> rowkey;
		std::unordered_map<char, bool> columnkey;
		std::unordered_map<char, bool> unitkey;

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
				rowkey.insert({ rkey,true });
			}

			char ckey = board[rj][ri];
			if (ckey != '.')
			{
				if (columnkey.find(ckey) != columnkey.end())
				{
					return false;
				}
				columnkey.insert({ ckey,true });
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
				unitkey.insert({ ukey,true });
			}
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
  EXPECT_TRUE(isValidSudoku(board));
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
	EXPECT_FALSE(isValidSudoku(board));
}