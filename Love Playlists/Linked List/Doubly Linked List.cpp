#include <bits/stdc++.h>
using namespace std;

// Doubly linklist
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << this->data << " : this node is deleted " << endl;
    }
};

int getlength(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reverseprint(Node *&tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void insertion_in_doubly_linklist(Node *&head, Node *&tail, int d, int position = -1)
{
    Node *new_node = new Node(d);
    Node *temp = head;

    if (position == 1)
    {
        new_node->next = temp;
        temp->prev = new_node;
        head = new_node;
        return;
    }

    else if (position == -1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->prev = temp;
        temp->next = new_node;
        tail = new_node;
        return;
    }

    else
    {
        int cnt = 1;

        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        Node *curr = temp->next;

        curr->prev = new_node;
        new_node->next = curr;

        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deletion_in_doubly_linklist(Node *&head, Node *&tail, int position = -1)
{
    Node *temp = head;

    if (position == 1)
    {
        head = temp->next;
        head->prev = NULL;
        temp->~Node();
        delete temp;
        return;
    }

    else if (position == -1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *prevs = temp->prev;
        prevs->next = NULL;
        tail = prevs;
        temp->~Node();
        delete temp;
        return;
    }

    else
    {
        int cnt = 1;

        while (cnt <= position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        Node *prevs = temp->prev;
        Node *nexts = temp->next;

        prevs->next = nexts;
        nexts->prev = prevs;

        temp->~Node();
        delete temp;
    }
}

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    for (int i = 4; i < 11; i++)
    {
        if (i == 7)
        {
            continue;
        }

        insertion_in_doubly_linklist(head, tail, i);
    }

    insertion_in_doubly_linklist(head, tail, 2, 1);
    insertion_in_doubly_linklist(head, tail, 1, 1);
    insertion_in_doubly_linklist(head, tail, 7, 7);

    cout << getlength(head) << endl;
    print(head);
    reverseprint(tail);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    deletion_in_doubly_linklist(head, tail, 5);
    deletion_in_doubly_linklist(head, tail, 1);
    deletion_in_doubly_linklist(head, tail);

    cout << getlength(head) << endl;
    print(head);
    reverseprint(tail);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
}
