#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

class Solution
{
public:
    // approach 1 brute force approach where we can search all list for every element O(n2) complexity
    // approach 2 we can sort the list and remove list but relative position of elements will change
    // approach 3 we can use a set to store the already visited elements

    Node *removeDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        set<int> isPresent;
        Node *prev = head;
        Node *curr = head->next;

        isPresent.insert(prev->data);

        while (curr != NULL)
        {
            int val = curr->data;
            set<int>::iterator it = isPresent.find(val);

            if (it != isPresent.end())
            {
                Node *to_delete = curr;
                curr = curr->next;
                prev->next = curr;
                to_delete->next = NULL;
                delete (to_delete);
            }

            else
            {
                isPresent.insert(val);
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