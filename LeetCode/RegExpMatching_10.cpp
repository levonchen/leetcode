
#include "pch.h"

#include "gtest/gtest.h"
#include <string>

using namespace std;

bool isMatch(string s, string p) {
	
	if (p.empty()) 
		return s.empty();
	if (p[1] == '*') 
		return (isMatch(s, p.substr(2)) || ((p[0] == s[0] || p[0] == '.') && !s.empty() && isMatch(s.substr(1), p)));
	else 
		return !s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));


}

TEST(RegExpMatching, functionone) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}