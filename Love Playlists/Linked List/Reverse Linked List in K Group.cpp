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
    // to check whether k nodes are present or not
    bool isPresent(ListNode *head, int k)
    {
        ListNode *curr = head;
        int nodes_cnt = 0;

        while (nodes_cnt < k && curr != NULL)
        {
            nodes_cnt++;
            curr = curr->next;
        }

        if (nodes_cnt == k)
        {
            return true;
        }
        
        return false;
    }

    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        if (isPresent(curr, k))
        {
            int nodes_cnt = 0;

            while (nodes_cnt < k)
            {
                ListNode *next_to_curr = curr->next;
                nodes_cnt++;
                curr->next = prev;
                prev = curr;
                curr = next_to_curr;
            }

            head->next = reverse(curr, k);
        }

        else
        {
            return head;
        }

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return reverse(head, k);
    }
};

int main()
{

    return 0;
}