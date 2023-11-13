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
    ListNode *getMiddle(ListNode *head)
    {
        // corner cases
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last_slow = slow;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            last_slow = slow;
            slow = slow->next;
        }

        // a node before middle node is pointed to NULL
        last_slow->next = NULL;

        return slow;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *curr1 = head1;
        ListNode *curr2 = head2;
        ListNode *merged_head = new ListNode(0);
        ListNode *curr = merged_head;

        // merge the sorted lists
        while (curr1 != NULL && curr2 != NULL)
        {
            int val1 = curr1->val;
            int val2 = curr2->val;

            if (val1 <= val2)
            {
                curr->next = curr1;
                curr1 = curr1->next;
            }

            else
            {
                curr->next = curr2;
                curr2 = curr2->next;
            }

            curr = curr->next;
        }

        if (curr1 != NULL)
        {
            curr->next = curr1;
        }

        if (curr2 != NULL)
        {
            curr->next = curr2;
        }

        ListNode *ans = merged_head->next;
        merged_head->next = NULL;
        ListNode *to_delete = merged_head;
        delete to_delete;

        return ans;
    }

    ListNode *merge_sort(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *middle = getMiddle(head);
        head = merge_sort(head);
        middle = merge_sort(middle);
        return (merge(head, middle));
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *sorted_head = merge_sort(head);
        return sorted_head;
    }
};

int main()
{

    return 0;
}