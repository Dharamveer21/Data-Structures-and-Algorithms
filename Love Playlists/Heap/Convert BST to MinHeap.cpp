#include <bits/stdc++.h>
using namespace std;

// Given -- The bst is also a complete binary tree
/*
The property of minHeap is Root < Left && Root < Right .
The property of BST is Left < Root .

Means if we merge them we can make -- Root < Left < Right -- it is also a minHeap
means if we get the sorted order of the BST -- inorder then we can push its values in a preorder traversal
of the tree where minValue is placed at root then bigger value in leftSubtree & biggest value in rightSubtree
*/

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

void inorderTraversal(BinaryTreeNode *root, vector<int> &inorder)
{
    BinaryTreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            BinaryTreeNode *prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }

            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

void preOrderFillBST(BinaryTreeNode *root, vector<int> &inorder)
{
    int index = 0;
    BinaryTreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            curr->data = inorder[index++];
            curr = curr->right;
        }

        else
        {
            BinaryTreeNode *prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr->data = inorder[index++];
                curr = curr->left;
            }

            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> inorder;

    inorderTraversal(root, inorder);
    preOrderFillBST(root, inorder);

    return root;
}

int main()
{

    return 0;
}