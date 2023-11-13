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
    // approach - 1 store in a array and then check
    // approach - 2 reverse the list after middle and then compare the two lists

    ListNode *getMiddle(ListNode *&head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode *&head)
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

    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = getMiddle(head);
        middle = reverse(middle);

        while (middle != NULL)
        {
            if (head->val != middle->val)
            {
                return false;
            }

            middle = middle->next;
            head = head->next;
        }

        return true;
    }
};

int main()
{

    return 0;
}