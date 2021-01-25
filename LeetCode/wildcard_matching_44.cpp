
#include "pch.h"
#include "gtest/gtest.h"

#include <queue>
#include <ostream>

using namespace std;

class Solution {
public:

	typedef struct Node {
		int sIndex;
		int pIndex;
	} *PNode;

	bool validate(string s, string p) {
		int row = p.length();
		int column = s.length();

		vector<vector<bool> > dp(row + 1, vector<bool>(column + 1));
		s = " " + s;
		p = " " + p;

		dp[0][0] = true;

		for (int j = 1; j <= column; j++) {
			dp[0][j] = false;
		}

		for (int i = 1; i <= row; i++) {
			if (p.at(i) == '*') {
				dp[i][0] = dp[i - 1][0];
			}
			else {
				dp[i][0] = false;
			}
		}

		for (int i = 1; i <= row; i++) {
			char pc = p.at(i);
			for (int j = 1; j <= column; j++) {
				if (pc == '*'){
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				} else if ( pc == '?'){
					dp[i][j] = dp[i - 1][j - 1];
				} 
				else{
					char tpc = s.at(j);
					dp[i][j] = (tpc == pc) && dp[i - 1][j - 1];
				}
			}
		}


		return dp[row][column];

	}
};

TEST(LC_44, wildcard_matching) {
	vector<int> stones{ 2,7,4,1,8,1 };

	Solution sl;	
	EXPECT_TRUE(sl.validate("adceb", "*a*b"));

	EXPECT_TRUE(sl.validate("", "**"));

	EXPECT_TRUE(sl.validate("aab", "aab*"));

	EXPECT_TRUE(sl.validate("abcabczzzde", "*abc???de*"));

	EXPECT_FALSE(sl.validate("aa", "a"));

	EXPECT_FALSE(sl.validate("cb", "?a"));

	EXPECT_FALSE(sl.validate("acdcb", "a*c?b"));
}