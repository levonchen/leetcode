
#include "pch.h"
#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{

	}
};


ListNode* merge(ListNode *p1, ListNode *p2)
{
	if (p1 && p2)
	{
		if (p1->val <= p2->val)
		{
			p1->next = merge(p1->next, p2);
			return p1;
		}
		else {
			p1->next = merge(p1, p2->next);
			return p2;

		}
	}

	return p1 ? p1 : p2;
}

ListNode* mergeKLists3(vector<ListNode*> &lists)
{
	queue<ListNode*> q;
	q.push(NULL);
	for (auto* item : lists) q.push(item);

	while (q.size() > 1)
	{
		auto *p1 = q.front();
		q.pop();
		auto *p2 = q.front();
		q.pop();

		q.push(merge(p1, p2));
	}

	return q.front();
}

ListNode* mergeKLists2(vector<ListNode*> &lists)
{
	if (lists.size() == 0) {
		return NULL;
	}
	int n_min = INT_MAX;
	int n_max = INT_MIN;

	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* pCur = lists[i];
		if (pCur == NULL)
			continue;

		n_min = std::min(pCur->val, n_min);
		n_max = std::max(pCur->val, n_max);

		while (pCur->next != NULL) {
			pCur = pCur->next;
		}
		n_max = std::max(pCur->val, n_max);
	}

	if (n_min == INT_MAX || n_max == INT_MIN)
		return NULL;

	int offset = n_min < 0 ? -1 * n_min : 0;
	int size = std::max(n_min * -1, n_max + offset);
	int *sorted = new int[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		sorted[i] = 0;
	}

	for (int i = 0; i < lists.size(); i++)
	{
		
		ListNode* cur = lists[i];
		while (cur != NULL) {
			sorted[cur->val + offset] ++;
			cur = cur->next;
		}
	}

	ListNode* pointer = new ListNode(0);
	ListNode* head = pointer;

	for (int i = 0; i < size + 1; i++)
	{
		int val = sorted[i];
		for (int j = 0; j < val; j++)
		{
			ListNode *next = new ListNode(i - offset);
			head->next = next;
			head = head->next;
		}
	}

	return pointer->next;

}

ListNode* mergeTwoList(ListNode* pBase, ListNode* pCur)
{
	ListNode *pRet = pBase;
	ListNode *pWaiting = pCur;

	if (pBase == NULL)
	{
		return pCur;
	}

	if (pCur == NULL)
	{
		return pBase;
	}

	if (pCur->val < pBase->val)
	{
		pRet = pCur;
		pWaiting = pBase;
	}

	ListNode *pCurrent = pRet;
	ListNode *pNext = pRet->next;

	while (true)
	{
		if (pNext == NULL)
		{
			pCurrent->next = pWaiting;
			break;
		}

		if (pWaiting == NULL)
		{
			break;
		}

		if (pWaiting->val < pNext->val)
		{
			ListNode* p = pWaiting->next;

			pCurrent->next = pWaiting;
			pCurrent = pWaiting;
			pWaiting->next = pNext;

			pWaiting = p;
		}
		else
		{
			pCurrent = pNext;
			pNext = pNext->next;
		}
	}
	

	return pRet;
}

ListNode* mergeKLists(vector<ListNode*> &lists)
{
	if (lists.size() == 0)
	{
		return NULL;
	}
	if (lists.size() == 1)
	{
		return lists[0];
	}
	ListNode* pBase = lists[0];

	int size = lists.size();
	for (int index = 1; index < size; index++)
	{
		ListNode* pCur = lists[index];
		pBase = mergeTwoList(pBase, pCur);
	}
	return pBase;
}

bool accepted()
{
	vector<ListNode*> lists;
	ListNode* arr1 = new ListNode(1);
	ListNode* p = arr1;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);

	lists.push_back(arr1);

	ListNode* arr2 = new ListNode(1);
	p = arr2;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);

	lists.push_back(arr2);

	ListNode* arr3 = new ListNode(2);
	p = arr3;
	p->next = new ListNode(6);
	lists.push_back(arr3);

	ListNode* rets = mergeKLists3(lists);
	p = rets;
	if (p == NULL) return false;
	if (p->val != 1) return false;
	p = p->next;
	if (p == NULL) return false;
	if (p->val != 1) return false;
	p = p->next;
	if (p == NULL) return false;

	return true;
}

bool accepted2()
{
	vector<ListNode*> lists;
	ListNode* arr1 = new ListNode(1);
	lists.push_back(arr1);

	ListNode* arr2 = new ListNode(0);
	lists.push_back(arr2);


	ListNode* rets = mergeKLists(lists);

	return true;
}

TEST(MergeKSortedLists, functionOne) {
  
  EXPECT_TRUE(accepted());
}