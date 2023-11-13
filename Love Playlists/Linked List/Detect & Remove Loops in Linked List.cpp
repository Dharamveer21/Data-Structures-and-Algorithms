#include <bits/stdc++.h>
using namespace std;

// detect where the cycle begins
class ListNode
{
public:
    int val;
    ListNode *next = NULL;
};

class Solution
{
public:
    // Approach 1 using unordered map

    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        unordered_map<ListNode *, bool> vis;
        ListNode *curr = head;

        while (curr != NULL && vis[curr] != true)
        {
            vis[curr] = true;
            curr = curr->next;
        }

        return curr;
    }

    // Approach 2 using floys cycle detection algorithm
    // first find the position where the fast and slow will meet in the loop
    // then from there we find the a + b = K * c
    // a - distance of cycle starting node from head
    // b - distance of meet of slow fast from where cycle starts
    // c - length of cycle

    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *fast = head, *slow = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;

            if (fast == slow)
            {
                isCycle = true;
                break;
            }
        }

        if (!isCycle)
        {
            return NULL;
        }

        slow = head;

        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

// Remove Loop 
class Node
{
public:
    int data;
    Node *next = NULL;
};

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes

        Node *curr = NULL;
        Node *fast = head, *slow = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;

            if (fast == slow)
            {
                isCycle = true;
                break;
            }
        }

        if (!isCycle)
        {
            return;
        }

        slow = head;

        while (slow != fast)
        {
            curr = fast;
            fast = fast->next;
            slow = slow->next;
        }

        if (fast != head)
        {
            curr->next = NULL;
            return;
        }

        curr = slow;

        while (curr->next != slow)
        {
            curr = curr->next;
        }

        curr->next = NULL;
    }
};

int main()
{
    return 0;
}