#include <bits/stdc++.h>
using namespace std;

// This traversal didnot require any extra sort_heap
//     TC : O(N) but SC : O(1)
// Threaded binary tree -- logic

// In order then one line change to convert it into pre order

// From the root i went to left & if left is not null i will connect the rightmost guy in the left subtree to
// the root make a thread then begins the traversal

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int data)
    {
        this->val = data;
    }
};

// Inorder
class Solution
{
public:
    vector<int> morris_inorder(TreeNode *root)
    {
        vector<int> inorder_traversal;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            // if left is NULL it means its the root so print it
            if (curr->left == NULL)
            {
                inorder_traversal.push_back(curr->val);
                curr = curr->right;
            }

            else
            {
                TreeNode *prev = curr->left;
                
                // check the thread on rightmost guy
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                // connect the thread
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                // remove thread & visit node then traverse to right
                else
                {
                    prev->right = NULL;
                    inorder_traversal.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder_traversal;
    }
};

// Preorder
class Solution
{
public:
    vector<int> morris_preorder(TreeNode *root)
    {
        vector<int> preorder_traversal;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            // if left is NULL it means its the root so print it
            if (curr->left == NULL)
            {
                preorder_traversal.push_back(curr->val);
                curr = curr->right;
            }

            else
            {
                TreeNode *prev = curr->left;
                // check the thread on rightmost guy
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                // connect the thread
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder_traversal.push_back(curr->val);
                    curr = curr->left;
                }

                // remove thread & visit node then traverse to right
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder_traversal;
    }
};

int main()
{

    return 0;
}