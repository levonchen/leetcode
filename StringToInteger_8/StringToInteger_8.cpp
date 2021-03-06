// StringToInteger_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"
#include "algorithm"
#include "limits.h"

using namespace std;


int myAtoi(string str) {

	int symbol = 1;
	bool hasStarted = false;
	double ret = 0;

	for (char x : str)
	{
		if(x == ' ' && !hasStarted)
			continue;

		if (x == '+' && !hasStarted)
		{
			hasStarted = true;
			continue;
		}

		if (x == '-' && !hasStarted)
		{
			hasStarted = true;
			symbol = -1;
			continue;
		}

		if (x >= 48 && x <= 57)
		{
			hasStarted = true;

			int t = x - 48;
			ret *= 10;
			ret += t;

			if (ret * symbol >= INT_MAX) {
				return INT_MAX;
			}

			if (ret * symbol <= INT_MIN)
			{
				return INT_MIN;
			}
		}
		else
		{
			break;
		}

	}
	return ret * symbol;
}

int main()
{
	int x = 0;
	x = INT_MAX + 1248;

	string  input = "   -42";
	int ret = myAtoi(input);

	input = "4193 with words";
	ret = myAtoi(input);

	input = "-91283472332";
	ret = myAtoi(input);

	input = "words and 987";
	ret = myAtoi(input);
	
    return 0;
}

