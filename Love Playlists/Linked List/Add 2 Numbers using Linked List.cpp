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
    ListNode *reverse(ListNode *&head, int &count)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            count++;
            ListNode *next_to_curr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_to_curr;
        }

        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int count1 = 0, count2 = 0, carry = 0;

        ListNode *ll1 = new ListNode(0);
        ListNode *ll2 = new ListNode(0);

        ll1->next = l1;
        ll2->next = l2;
        l1 = ll1;
        l2 = ll2;

        l1 = reverse(l1, count1);
        l2 = reverse(l2, count2);
        ListNode *ans, *curr;

        if (count1 >= count2)
        {
            ans = l1;
            curr = l1;
        }

        else
        {
            ans = l2;
            curr = l2;
        }

        while (l1 != NULL && l2 != NULL)
        {
            int val1 = l1->val;
            int val2 = l2->val;

            curr->val = (carry + val1 + val2) % 10;
            carry = (carry + val1 + val2) / 10;

            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }

        while (l1 != NULL)
        {
            int val1 = l1->val;

            curr->val = (carry + val1) % 10;
            carry = (carry + val1) / 10;

            l1 = l1->next;
            curr = curr->next;
        }

        while (l2 != NULL)
        {
            int val2 = l2->val;

            curr->val = (carry + val2) % 10;
            carry = (carry + val2) / 10;

            l2 = l2->next;
            curr = curr->next;
        }

        ans = reverse(ans, count1);

        if (ans->val != 0)
        {
            return (ans);
        }

        else
        {
            return (ans->next);
        }
    }
};

int main()
{
    return 0;
}