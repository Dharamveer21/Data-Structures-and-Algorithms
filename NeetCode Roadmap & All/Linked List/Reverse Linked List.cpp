#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We can use recursion in this problem , we can make a recursive function which will return us the
head & tail of the reversed list . we can take out first element & apply it on the rest of the list & connect
the element to tail of the list & return the head of the reversed list.

Approach 2 -- We take 3 pointers , prev , curr & next and we just connect curr to prev & forward them in the
manner like prev = curr, curr = next & next = next->next . Until curr is not equal to NULL . Return the prev.
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
    pair<ListNode *, ListNode *> reverseLinkedList(ListNode *head)
    {
        if (head->next == NULL)
            return {head, head};

        ListNode *currNode = head;
        auto reversedList = reverseLinkedList(head->next);

        ListNode *reversedNodeHead = reversedList.first;
        ListNode *reversedNodeTail = reversedList.second;

        reversedNodeTail->next = currNode;
        currNode->next = NULL;

        return {reversedNodeHead, currNode};
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *reversedHead = NULL;

        if (head == NULL)
            return reversedHead;

        reversedHead = reverseLinkedList(head).first;
        return reversedHead;
    }
};

// TC : O(N) -- traversing the full list
// SC : O(N) -- recursion stack space

// Approach 2
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *reversedHead = NULL;

        if (head == NULL)
            return reversedHead;

        ListNode *prevNode = NULL, *currNode = head;
        ListNode *nextNode = currNode->next;

        while (currNode != NULL)
        {
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
            nextNode = ((nextNode != NULL) ? nextNode->next : NULL);
        }

        reversedHead = prevNode;
        return reversedHead;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}