
#include "pch.h"
#include "gtest/gtest.h"

#include <queue>


using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int, vector<int>, less<int> > q;
		for (int s : stones)
			q.push(s);
		while (q.size() > 1) {
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();

			if (x == y) continue;

			q.push(abs(x - y));
		}
		return q.empty() ? 0 : q.top();
	}
};

TEST(LC_1046, lastStoneWeight) {
	vector<int> stones{2,7,4,1,8,1 };

	Solution sl;
	int ret = sl.lastStoneWeight(stones);

	EXPECT_TRUE(ret == 1);
}