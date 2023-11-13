#include <bits/stdc++.h>
using namespace std;

/*every node will be a doubly linklist & edges using pointers*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int main()
{
    Node *root = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    return 0;
}