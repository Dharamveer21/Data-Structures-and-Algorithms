#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we can use fast & slow pointers , where fast will move 2 pointers at a time and slow will
move 1 pointer at a time . If the list had loop then there is relative motion of 1 node per move between
slow & fast pointers , eventually they will meet at a point . If there is no loop the fast will get NULL first
and they will never able to meet . Hence , this way we can calculate if there is loop or not in the list .
*/

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
          
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}