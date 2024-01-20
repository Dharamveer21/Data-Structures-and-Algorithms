#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
protected:
    int countNodes(Node *root)
    {
        int nodeCnt = 0;
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                nodeCnt++;
                curr = curr->right;
            }

            else
            {
                Node *prev = curr->left;

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
                    nodeCnt++;
                    curr = curr->right;
                }
            }
        }

        return nodeCnt;
    }

    bool isCompleteBinaryTree(int ind, int nodeCnt, Node *root)
    {
        if (root == NULL || ind > nodeCnt)
        {
            return (root == NULL);
        }

        int leftChildInd = 2 * ind;
        int rightChildInd = 2 * ind + 1;

        return (isCompleteBinaryTree(leftChildInd, nodeCnt, root->left) && isCompleteBinaryTree(rightChildInd, nodeCnt, root->right));
    }

    bool isMaxHeap(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int rootVal = root->data;

        if (root->left != NULL)
        {
            Node *leftChild = root->left;
            int leftVal = leftChild->data;

            if (leftVal > rootVal)
            {
                return false;
            }
        }

        if (root->right != NULL)
        {
            Node *rightChild = root->right;
            int rightVal = rightChild->data;

            if (rightVal > rootVal)
            {
                return false;
            }
        }

        return (isMaxHeap(root->left) && isMaxHeap(root->right));
    }

public:
    bool isHeap(Node *tree)
    {
        Node *root = tree;
        int nodeCnt = countNodes(root);

        return (isCompleteBinaryTree(1, nodeCnt, root) && isMaxHeap(root));
    }
};

int main()
{

    return 0;
}