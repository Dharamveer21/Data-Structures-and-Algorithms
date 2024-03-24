#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We can reverse the second half of the list so that we can use two pointer to on firstHalf of list 
and the reversed of the secondHalf of the list . We join them one by one until it reaches its end .

Approach 2 -- We can use the basic concept of the recursion is that when it reached the base condition then it 
reverted back . We can use this reverted values for joining with the curr index
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

// Approach 1
class Solution
{
protected:
    ListNode *middleOfLinkedList(ListNode *head)
    {
        ListNode *tailOfFirstHalf = head;
        ListNode *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            tailOfFirstHalf = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        tailOfFirstHalf = ((fast == NULL) ? tailOfFirstHalf : tailOfFirstHalf->next);
        ListNode *middleNodeOfLinkedList = ((fast == NULL) ? slow : slow->next);

        tailOfFirstHalf->next = NULL;
        return middleNodeOfLinkedList;
    }

    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prevNode = NULL, *currNode = head;
        ListNode *nextNode = currNode->next, *reversedHead;

        while (currNode != NULL)
        {
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
            nextNode = ((nextNode == NULL) ? NULL : nextNode->next);
        }

        reversedHead = prevNode;
        return reversedHead;
    }

public:
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        
        ListNode *headOfFirstHalf = head;
        ListNode *headOfSecondHalf = middleOfLinkedList(head);
        ListNode *headOfReverseOfSecondHalf = reverseLinkedList(headOfSecondHalf);

        ListNode *curr1 = headOfFirstHalf;
        ListNode *curr2 = headOfReverseOfSecondHalf;

        while (curr2 != NULL)
        {
            ListNode *next1 = curr1->next;
            ListNode *next2 = curr2->next;

            curr1->next = curr2;
            curr2->next = next1;

            curr1 = next1;
            curr2 = next2;
        }
    }
};

// TC : O(N)
// SC : O(1)

// Approach 2
class Solution
{
public:
    void reorderList(ListNode *head)
    {
    }
};

// TC : O(N) -- traversing the list
// SC : O(N) -- recursion stack space

int main()
{

    return 0;
}