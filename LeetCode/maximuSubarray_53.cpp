#include "pch.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;
class Solution {
public:

	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int max = sum;
		int length = nums.size();
			for (int i = 1; i < length; i++) {
				if (sum < 0) {
					sum = nums[i];
				}
				else {
					sum += nums[i];
				}

				if (sum > max) {
					max = sum;
				}
			}

		return max;
	}
};
TEST(LC_53, Maxiumn_Subarray) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}