#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// approach 1 - where we calculate the distance of random pointer from first node in original node then we will use this dist and put the pointer in second node
// it is a TC : O(n2) , SC : O(1);

// approach 2 where we can store the mapping of a every list of node 1 and node 2
// then we can put random pointers in O(1)
// it is a TC : O(n) , SC : O(n);

class Solution
{
public:
    Node *createNode(int val)
    {
        Node *new_node = new Node(val);
        return new_node;
    }

    Node *setRandom_pointers(Node *&old_head, Node *&new_head, unordered_map<Node *, Node *> &mapp)
    {
        Node *old_curr = old_head;
        Node *new_curr = new_head;

        while (old_curr != NULL)
        {
            Node *random_pointer = old_curr->random;

            if (random_pointer == NULL)
            {
                new_curr->random = NULL;
            }

            else
            {
                new_curr->random = mapp[random_pointer];
            }

            old_curr = old_curr->next;
            new_curr = new_curr->next;
        }

        return new_head;
    }

    Node *copyRandomList(Node *head)
    {
        int value;
        Node *curr = head;
        Node *new_prev = NULL;
        Node *new_curr;
        Node *new_head;

        unordered_map<Node *, Node *> mapp;

        while (curr != NULL)
        {
            value = curr->val;
            new_curr = createNode(value);

            if (new_prev != NULL)
            {
                new_prev->next = new_curr;
            }

            else
            {
                new_head = new_curr;
            }

            new_prev = new_curr;
            mapp[curr] = new_curr;
            curr = curr->next;
        }

        return (setRandom_pointers(head, new_head, mapp));
    }
};

/* approach 3 - where we have to change links and doesn't take map
 so we actually map old list with clone list in

   1 2 3 4 5 6 7 -- old list
   |/|/|/|/|/|/
   1 2 3 4 5 6 7 -- new list

   TC : O(n), SC : O(1)
*/

class Solution
{
public:
    Node *createNode(int val)
    {
        Node *new_node = new Node(val);
        return new_node;
    }

    Node *copyRandomList(Node *head)
    {

        int value;
        Node *old_prev = NULL;
        Node *old_curr = head;
        Node *new_prev = NULL;
        Node *new_curr = NULL;
        Node *new_head = NULL;

        // create clone node
        while (old_curr != NULL)
        {
            value = old_curr->val;
            new_curr = createNode(value);

            if (new_prev != NULL)
            {
                new_prev->next = new_curr;
            }

            else
            {
                new_head = new_curr;
            }

            new_prev = new_curr;
            old_curr = old_curr->next;
        }

        old_curr = head;
        new_curr = new_head;

        // create mapping
        while (old_curr != NULL)
        {
            Node *next_old_curr = old_curr->next;
            Node *next_new_curr = new_curr->next;

            old_curr->next = new_curr;
            new_curr->next = next_old_curr;

            old_curr = next_old_curr;
            new_curr = next_new_curr;
        }

        old_curr = head;

        // point the random pointers
        while (old_curr != NULL)
        {
            new_curr = old_curr->next;

            Node *rando = old_curr->random;

            if (rando == NULL)
            {
                new_curr->random = NULL;
            }

            else
            {
                new_curr->random = rando->next;
            }

            old_curr = old_curr->next->next;
        }

        old_prev = NULL;
        old_curr = head;
        new_prev = NULL;
        new_curr = new_head;

        // point the next pointers of clone list & original_list
        while (old_curr != NULL)
        {
            if (old_prev != NULL && new_prev != NULL)
            {
                old_prev->next = old_curr;
                new_prev->next = new_curr;
            }

            old_prev = old_curr;
            new_prev = new_curr;

            old_curr = new_curr->next;

            if (old_curr != NULL)
                new_curr = old_curr->next;

            else
                new_curr->next = NULL;
        }

        if (old_prev != NULL)
            old_prev->next = NULL;

        return new_head;
    }
};

int main()
{
    
    return 0;
}