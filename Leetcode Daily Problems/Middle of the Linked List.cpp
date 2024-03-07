#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can find it using the slow & fast pointer , whenever fast pointer becomes NULL slow will be at
middle of the linked list . Hence , we return the pointer of the middle node .
*/

class ListNode
{
public:
    int val;
    ListNode *next = NULL;

    ListNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *middleNode = slow;
        return middleNode;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}