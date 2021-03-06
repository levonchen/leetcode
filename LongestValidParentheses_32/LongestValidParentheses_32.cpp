// LongestValidParentheses_32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"
#include "vector"
#include "algorithm"
#include <stack>

using namespace std;


int longestValidParentheses(string s) {
	stack<int> indexContainer;
	indexContainer.push(-1);
	int maxLength = 0;
	int index = 0;
	int lastLength = 0;

	for (char x : s) {		
		if (x == '(') {
			indexContainer.push(index);
		}
		else {

			indexContainer.pop();
			if (indexContainer.empty())
			{
				indexContainer.push(index);
			}
			else
			{				
				maxLength = max(maxLength, index-indexContainer.top());
			}
		}
		index++;
	}
	return maxLength;
}

int main()
{
	string input1 = "()";

	int ret = longestValidParentheses(input1);

	string input2 = ")()())";
	ret = longestValidParentheses(input2);

    return 0;
}

