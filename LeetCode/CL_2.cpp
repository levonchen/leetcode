#include "pch.h"
#include "gtest/gtest.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* root = new ListNode(0);

		ListNode* next = root;

		int lastAdd = 0;
		while (true)
		{
			if (l1 != NULL && l2 != NULL)
			{
				int ct = l1->val + l2->val;
				if (lastAdd == 1)
				{
					ct += 1;
				}
				if (ct >= 10)
				{
					lastAdd = 1;
					ct = ct % 10;
				}
				else
				{
					lastAdd = 0;
				}

				next->next = new ListNode(ct);
				next = next->next;

				l1 = l1->next;
				l2 = l2->next;
			}
			else
			{
				ListNode* pLeft = l1 != NULL ? l1 : l2 ;
				if (pLeft != NULL)
				{
					next->next = pLeft;
					next = next->next;
					if (lastAdd == 1)
					{
						while (next != NULL)
						{
							lastAdd = 0;
							int cv = next->val + 1;
							if (cv == 10)
							{
								next->val = 0;
								lastAdd = 1;

								if (next->next == NULL)
								{
									next->next = new ListNode(1);
									lastAdd = 0;
									next = NULL;
								}
								else
								{
									next = next->next;
								}

							}
							else
							{
								next->val = cv;							
								next = next->next;
								break;
							}
						}
					}

				}

				break;
			}
		}

		if (lastAdd == 1)
		{
			next->next = new ListNode(1);
		}

		return root->next;
	}
};



TEST(CL_2, addTwoNumbers1) {


  ListNode* l1 = new ListNode(2);
  ListNode* p = l1;
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
   p = l2;
  p->next = new ListNode(6);
  p = p->next;
  p->next = new ListNode(4);


  Solution sl;
  ListNode* ret = sl.addTwoNumbers(l1, l2);

  ASSERT_TRUE(ret != NULL);
  EXPECT_EQ(ret->val, 7);
  ret = ret->next;
  ASSERT_TRUE(ret != NULL);
  EXPECT_EQ(ret->val, 0);
  ret = ret->next;
  ASSERT_TRUE(ret != NULL);
  EXPECT_EQ(ret->val, 8);

}

TEST(CL_2, addTwoNumbers2) {


	ListNode* l1 = new ListNode(9);
	ListNode* p = l1;
	p->next = new ListNode(8);
	p = p->next;
	p->next = new ListNode(1);

	ListNode* l2 = new ListNode(1);


	Solution sl;
	ListNode* ret = sl.addTwoNumbers(l1, l2);

	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 0);
	ret = ret->next;
	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 9);

}

TEST(CL_2, addTwoNumbers3) {

	ListNode* l1 = new ListNode(5);
	ListNode* l2 = new ListNode(5);

	Solution sl;
	ListNode* ret = sl.addTwoNumbers(l1, l2);

	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 0);
	ret = ret->next;
	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 1);

}


TEST(CL_2, addTwoNumbers4) {


	ListNode* l1 = new ListNode(9);
	ListNode* p = l1;
	p->next = new ListNode(9);


	ListNode* l2 = new ListNode(1);


	Solution sl;
	ListNode* ret = sl.addTwoNumbers(l1, l2);

	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 0);
	ret = ret->next;
	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 0);

	ret = ret->next;
	ASSERT_TRUE(ret != NULL);
	EXPECT_EQ(ret->val, 0);

}