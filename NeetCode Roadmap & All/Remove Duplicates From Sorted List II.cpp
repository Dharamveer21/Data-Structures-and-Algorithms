#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next = NULL;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

class Solution
{
public:
    void join_link(ListNode *&tail, ListNode *&curr)
    {
        tail->next = curr;
        tail = tail->next;
    }

    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *ans_head = new ListNode(-1);
        ListNode *ans_tail = ans_head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next_to_curr = head->next;

        while (curr != NULL)
        {
            int prev_val;
            int curr_val;
            int next_val;

            if (prev != NULL)
                prev_val = prev->val;
            else
                prev_val = -101;

            curr_val = curr->val;

            if (next_to_curr != NULL)
                next_val = next_to_curr->val;
            else
                next_val = 101;

            if (curr_val != prev_val && curr_val != next_val)
            {
                join_link(ans_tail, curr);
            }

            prev = curr;
            curr = next_to_curr;

            if (next_to_curr != NULL)
            {
                next_to_curr = next_to_curr->next;
            }
        }

        ans_tail->next = NULL;
        ListNode *ans = ans_head->next;
        ans_head->next = NULL;
        delete ans_head;
        return (ans);
    }
};

int main()
{

    return 0;
}