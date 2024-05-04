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
    ListNode *middle_itera(ListNode *&head)
    {
        ListNode *middle_curr = head;
        ListNode *curr = head;

        while (curr != NULL || curr->next != NULL)
        {
            curr = curr->next->next;
            middle_curr = middle_curr->next;
        }

        return middle_curr;
    }

    ListNode *middleNode(ListNode *head)
    {
        return (middle_itera(head));
    }
};

int main()
{

    return 0;
}