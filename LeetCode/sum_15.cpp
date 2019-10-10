#include "pch.h"

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*
not good method
*/
vector<vector<int>> threeSum1(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	int nsize = nums.size() - 2;

	vector<vector<int>> rets;

	unordered_map<string,int> existed;

	for (int index = 0; index < nsize; index ++)
	{
		int num1 = nums[index];

		for (int y = index + 1; y < nsize + 1; y++)
		{
			int num2 = nums[y];

			for (int z = y + 1; z < nsize + 2; z++)
			{
				int num3 = nums[z];

				if (num1 + num2 + num3 == 0)
				{
					std::ostringstream os;
					os << num1 << num2 << num3;
					std::string key = os.str();

					if (existed.find(key) != existed.end())
						continue;

					vector<int> ret;
					ret.push_back(num1);
					ret.push_back(num2);
					ret.push_back(num3);


					existed.insert(std::make_pair(key, 1));
					rets.push_back(ret);
				}
			}
		
		}
	}

	return rets;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector <vector <int>> res;
	vector <int> temp(3);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		//if (i > 0 && nums[i] == nums[i - 1]) continue;
		temp[0] = nums[i];
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] == 0)
			{
				temp[1] = nums[left];
				temp[2] = nums[right];
				res.push_back(temp);
				while (left < right && nums[left + 1] == nums[left]) left++;
				while (left < right && nums[right - 1] == nums[right]) right--;
				left++;
				right--;
			}
			else if (nums[i] + nums[left] + nums[right] < 0) left++;
			else right--;
		}
	}
	return res;
}

bool test()
{
	vector<int> inputs = { -1,0,1,2,-1,-4 };

	auto rets = threeSum(inputs);

	return rets.size() == 2;
}

bool test2()
{
	vector<int> inputs = { 0,0,0,0,0,0,0,0};

	auto rets = threeSum(inputs);

	return rets.size() == 1;
}

bool test3()
{
	vector<int> inputs = { -1,0,1,0};

	auto rets = threeSum(inputs);

	return rets.size() == 1;
}


TEST(Sum15, functionOne) {

	EXPECT_TRUE(test());
  EXPECT_TRUE(test3());
  //EXPECT_TRUE(test2());
}