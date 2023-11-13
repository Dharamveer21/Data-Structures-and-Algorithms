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

void floor_val(Node *root, int &val, int &floor)
{
    if (root == NULL)
    {
        return;
    }

    if (val == root->data)
    {
        floor = root->data;
        return;
    }

    if (val < root->data)
    {
        floor_val(root->left, val, floor);
    }

    else
    {
        floor = root->data;
        floor_val(root->right, val, floor);
    }
}

int floor(Node *root, int x)
{
    int floor = -1;
    floor_val(root, x, floor);
    return floor;
}

int main()
{

    return 0;
}
