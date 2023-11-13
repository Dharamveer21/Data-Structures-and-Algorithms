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
    void insert_in_merged_list(ListNode *&tail, ListNode *&curr)
    {
        tail->next = curr;
        tail = tail->next;
    }

    // approach two pointers
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merged_head = new ListNode(0);
        ListNode *merged_tail = merged_head;

        ListNode *curr1 = list1;
        ListNode *curr2 = list2;

        while (curr1 != NULL && curr2 != NULL)
        {
            int val1 = curr1->val;
            int val2 = curr2->val;

            if (val1 <= val2)
            {
                insert_in_merged_list(merged_tail, curr1);
                curr1 = curr1->next;
            }

            else
            {
                insert_in_merged_list(merged_tail, curr2);
                curr2 = curr2->next;
            }
        }

        if (curr1 == NULL && curr2 == NULL)
        {
            return (merged_head->next);
        }

        if (curr1 == NULL)
        {
            insert_in_merged_list(merged_tail, curr2);
        }

        else
        {
            insert_in_merged_list(merged_tail, curr1);
        }

        return (merged_head->next);
    }
};

int main()
{

    return 0;
}