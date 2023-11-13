#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class Solution
{
public:
    // approach 1 - we count no of 0 1 2 and then change the data
    Node *segregate(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        int count_0 = 0, count_1 = 0, count_2 = 0;

        while (curr != NULL)
        {
            int val = curr->data;

            if (val == 0)
            {
                count_0++;
            }

            if (val == 1)
            {
                count_1++;
            }

            if (val == 2)
            {
                count_2++;
            }
        }

        curr = head;

        while (count_0--)
        {
            curr->data = 0;
            curr = curr->next;
        }

        while (count_1--)
        {
            curr->data = 1;
            curr = curr->next;
        }

        while (count_2--)
        {
            curr->data = 2;
            curr = curr->next;
        }

        return head;
    }
};

class Solution
{
public:
    // approach 2 - data replacement is not allowed
    // we make 3 linklists with dummy nodes

    void join_link(Node *&tail, Node *&curr)
    {
        tail->next = curr;
        tail = tail->next;
    }

    Node *segregate(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *head0 = new Node(-1);
        Node *head1 = new Node(-1);
        Node *head2 = new Node(-1);

        Node *tail0 = head0;
        Node *tail1 = head1;
        Node *tail2 = head2;

        Node *curr = head;
        Node *ans = NULL;

        while (curr != NULL)
        {
            int val = curr->data;

            if (val == 0)
            {
                join_link(tail0, curr);
            }

            if (val == 1)
            {
                join_link(tail1, curr);
            }

            if (val == 2)
            {
                join_link(tail2, curr);
            }

            curr = curr->next;
        }

        if (head0->next == NULL)
        {
            if (head1->next == NULL)
            {
                ans = head2->next;
            }

            else
            {
                tail1->next = head2->next;
                ans = head1->next;
            }
        }

        else
        {
            if (head1->next == NULL)
            {
                tail0->next = head2->next;
                ans = head0->next;
            }

            else
            {
                tail0->next = head1->next;
                tail1->next = head2->next;
                ans = head0->next;
            }
        }

        tail2->next = NULL;

        delete head0;
        delete head1;
        delete head2;

        return ans;
    }
};

int main()
{

    return 0;
}