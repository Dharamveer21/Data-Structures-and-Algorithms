#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        this->data = val;
    }
};

void ceil_val(Node *root, int &val, int &ceil)
{
    if (root == NULL)
    {
        return;
    }

    if (val == root->data)
    {
        ceil = root->data;
        return;
    }

    if (val < root->data)
    {
        ceil = root->data;
        ceil_val(root->left, val, ceil);
    }

    else
    {
        ceil_val(root->right, val, ceil);
    }
}

int findCeil(Node *root, int input)
{
    int ceil = -1;
    ceil_val(root, input, ceil);
    return ceil;
}

int main()
{

    return 0;
}
