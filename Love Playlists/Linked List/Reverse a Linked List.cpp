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
    // Recurisve
    void reverse(ListNode *prev, ListNode *curr, ListNode *&head)
    {
        if (curr == NULL)
        {
            head = prev;
            return;
        }

        reverse(curr, curr->next, head);
        curr->next = prev;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *&new_head = head;
        reverse(NULL, head, new_head);
        return new_head;
    }

    // Iterative
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *next_to_curr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_to_curr;
        }

        return prev;
    }
};

int main()
{

    return 0;
}