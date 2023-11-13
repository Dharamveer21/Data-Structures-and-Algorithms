#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    void join_two_lists(Node *head, Node *child)
    {
        Node *last_node = head->next;
        Node *curr = child;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        head->next = child;
        child->prev = head;

        curr->next = last_node;

        if (last_node != NULL)
        {
            last_node->prev = curr;
        }

        head->child = NULL;
    }

    Node *flat_the_list(Node *head)
    {
        Node *curr = head;

        while (curr != NULL)
        {
            Node *child = curr->child;
            Node *new_curr = curr->next;

            if (curr->child != NULL)
            {
                new_curr = curr->next;
                flat_the_list(child);
                join_two_lists(curr, child);
            }

            curr = new_curr;
        }

        return head;
    }

    Node *flatten(Node *head)
    {
        return flat_the_list(head);
    }
};

int main()
{

    return 0;
}