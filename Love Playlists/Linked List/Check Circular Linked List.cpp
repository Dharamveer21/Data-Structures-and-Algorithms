#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next = NULL;
};

class Solution
{
public:

    //floyds cycle detection algorithm for finding is cycle exists or not
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}