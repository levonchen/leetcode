// ZigZagConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

string convert1(string s, int numRows) {
	if (numRows <= 1)
	{
		return s;
	}
	int blockCount = numRows + numRows - 2;
	int blockColumnCount = numRows - 1;

	int count = s.size();

	int totalBlockleft = count % blockCount;

	int totalBlock = count / blockCount;

	if (totalBlockleft > 0)
	{
		totalBlock += 1;
	}

	int totalColumn = totalBlock * blockColumnCount;

	char **itemContainer = new char*[numRows];
	for (int i = 0; i < numRows; i++)
	{
		itemContainer[i] = new char[totalColumn];

		for (int j = 0; j < totalColumn; j++)
		{
			itemContainer[i][j] = '\0';
		}
	}
	
	int nIndex = 0;
	int nColumn = 0;
	for (int i = 0; i < numRows && nIndex < count; )
	{
		char v = s.at(nIndex++);

		itemContainer[i][nColumn] = v;
		if (nIndex >= count)
		{
			break;
		}
		i++;

		if (i == numRows)
		{
			for (i = numRows - 2; i > 0; i--)
			{
				nColumn++;
				char v = s.at(nIndex++);

				itemContainer[i][nColumn] = v;
				if (nIndex >= count)
				{
					break;
				}

			}
			nColumn++;
			i = 0;
		}
	}

	string ret = "";
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < totalColumn; j++)
		{
			
			char v = itemContainer[i][j] ;
			if (v != '\0')
			{
				ret = ret + v;
			}
		}
	}

	return ret;
}


string convert(string s, int numRows) {
	if (numRows == 1) return s;

	vector<string> rows(min(numRows, int(s.size())));

	int curRow = 0;
	int goingDown = -1;
	int maxRow = numRows - 1;
	for (char c : s) {
		rows[curRow] += c;
		if (curRow == 0 || curRow == maxRow)
			goingDown = -goingDown;
		curRow += goingDown;
	}

	string ret;
	for (string row : rows) ret += row;
	return ret;

}

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 3;

	string ret = convert(s, numRows);

	if (ret.compare("PAHNAPLSIIGYIR") != 0) {
		return -1;
	}

    return 0;
}

