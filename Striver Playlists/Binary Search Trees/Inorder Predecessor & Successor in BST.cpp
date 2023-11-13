#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data)
    {
        this->key = data;
    }
};

class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        suc = NULL;
        pre = NULL;
        Node *node = root;

        // for succesor
        while (true)
        {
            if (node == NULL)
            {
                break;
            }

            if (node->key > key)
            {
                suc = node;
                node = node->left;
            }

            else
            {
                node = node->right;
            }
        }

        node = root;
        // for precedor
        while (true)
        {
            if (node == NULL)
            {
                break;
            }

            if (node->key < key)
            {
                pre = node;
                node = node->right;
            }

            else
            {
                node = node->left;
            }
        }
    }
};

int main()
{

    return 0;
}