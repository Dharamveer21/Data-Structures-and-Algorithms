#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Store the inorder of the Binary Search Tree
Create the balanced BST from that sorted array using binary search
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
protected:
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }

            else
            {
                TreeNode *prev = curr->left;

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
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    
    TreeNode *convertIntoBST(int start, int end, vector<int> &inorder)
    {
        if (start > end)
        {
            return NULL;
        }
        
        int mid = ((start + end) >> 1);
        int val = inorder[mid];
        
        TreeNode *root = new TreeNode(val);

        root->left = convertIntoBST(start, mid - 1, inorder);
        root->right = convertIntoBST(mid + 1, end, inorder);

        return root;
    }
    
public:
    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        vector<int> inorder;
        inorderTraversal(root, inorder);

        int start = 0;
        int end = inorder.size() - 1;

        TreeNode *newRoot = convertIntoBST(start, end, inorder);
        return newRoot;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{
    return 0;
}