#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can calculate the length of the linkedlist & then travel (L-n) nodes from beginning using prev &
curr pointers . finally when we reach desiderd node we can connect prev with curr->next . But it will be a 2
pass solution . In one pass solution we can consider the fact that first of all we can run a curr pointer to
n nodes from beginning . Now when it reached the nth node there are (L-n) nodes are left to traverse , we can
take a prev pointer & now move both prev & curr simultaneously . now when curr will reach the end it will have
traverse n nodes , the prev will be traverlled n nodes and it will be at right position in one pass .
Consider some corner cases where head is to be removed .
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = head, *prev = head;
        ListNode *newHead = head->next;
        int nodeNumber = n + 1;

        while (nodeNumber--)
        {
            // if head is deleted
            if (curr == NULL)
            {
                delete head;
                return newHead;
            }

            curr = curr->next;
        }

        while (curr != NULL)
        {
            prev = prev->next;
            curr = curr->next;
        }

        ListNode *nextNode = prev->next;
        ListNode *nextToNextNode = nextNode->next;

        delete nextNode;
        prev->next = nextToNextNode;

        return head;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{
    return 0;
}