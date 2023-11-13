#include <bits/stdc++.h>
using namespace std;

// Circular Linklist
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << this->data << " : this node is deleted" << endl;
    }
};

void insert(Node *&tail, int element, int data)
{
    // if list is empty
    if (tail == NULL)
    {
        Node *new_node = new Node(data);
        new_node->next = new_node;
        tail = new_node;
        return;
    }

    // if list is not empty
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // means we got element
        Node *new_node = new Node(data);
        new_node->next = curr->next;
        curr->next = new_node;

        // to point tail
        if (tail->data <= new_node->data)
        {
            tail = new_node;
        }
    }
}

void deletion(Node *&tail, int data)
{
    Node *prev = tail;
    Node *curr = tail->next;

    while (curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    Node *to_delete = curr;
    prev->next = curr->next;

    if (tail == curr)
    {
        tail = prev;
    }

    delete to_delete;
}

void print(Node *&tail)
{
    Node *curr = tail->next;

    while (curr != tail)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << tail->data << endl;
}

int main()
{
    Node *tail = NULL;

    insert(tail, 5, 1);
    print(tail);

    insert(tail, 1, 2);
    print(tail);

    insert(tail, 2, 3);
    print(tail);

    insert(tail, 3, 5);
    print(tail);

    insert(tail, 3, 4); 
    print(tail);

    deletion(tail, 3);
    print(tail);

    deletion(tail, 1);
    print(tail);

    return 0;
}