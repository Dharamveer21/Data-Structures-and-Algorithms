#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next = NULL;
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // to check prev & curr are equal or not

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *curr = head->next;
        ListNode *prev = head;

        while (curr != NULL)
        {
            if (prev->val == curr->val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }

            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main()
{

    return 0;
}