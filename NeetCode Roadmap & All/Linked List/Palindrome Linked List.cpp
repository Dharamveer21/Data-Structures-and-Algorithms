#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Find the middle of the list & reverse the other half of the list & compare its values one by one
with first half of the list . If any value is not equal we will return false otherwise true .

Approach 2 -- In this solution we are not going to change the list (means we are not going to reverse it) we can
do it by using the concept of recursion returned after the base case . We the recursion is returning we compare
it with the currNode which is started from starting of the list . if at any point the values are not equal then
we can return false . Else We can return prevAns && true & final ans will contain is string palindrome or not .
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
    ListNode *headOfSecondHalfOfList(ListNode *head)
    {
        ListNode *tailOfFirstHalf = NULL;
        ListNode *headOfSecondHalf = NULL;
        ListNode *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            tailOfFirstHalf = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        tailOfFirstHalf->next = NULL;
        headOfSecondHalf = ((fast == NULL) ? slow : slow->next);
        return headOfSecondHalf;
    }

    ListNode *reverseList(ListNode *head)
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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode *headOfFirstHalf = head;
        ListNode *headOfSecondHalf = headOfSecondHalfOfList(head);
        ListNode *headOfReversedSecondHalf = reverseList(headOfSecondHalf);

        ListNode *curr1 = headOfFirstHalf;
        ListNode *curr2 = headOfReversedSecondHalf;

        while (curr1 != NULL)
        {
            int val1 = curr1->val;
            int val2 = curr2->val;

            if (val1 != val2)
                return false;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return true;
    }
};

// TC : O(N)
// SC : O(1)

// Approach 2
class Solution
{
    bool isLinkedListPalindrome(ListNode *node, ListNode *&curr)
    {
        if (node == NULL)
            return true;

        bool isListPalindrome = isLinkedListPalindrome(node->next, curr);
        int frontVal = curr->val, backVal = node->val;

        if (frontVal != backVal)
            return false;

        curr = curr->next;
        return isListPalindrome;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        bool isListPalindrome = isLinkedListPalindrome(head, head);
        return isListPalindrome;
    }
};

// TC : O(N) -- traversing the list
// SC : O(N) -- recusion stack space

int main()
{

    return 0;
}