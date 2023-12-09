#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Using Recursion
Here we just have to write method for getting left by recursion , root by myself & again right by recursion
base case will be when root is NULL

Approach 2 -- using iteration , stack & while loop
take a node which will point to curr node , first put nothing in the stack
there are 2 conditons , if & else
if node is non null, means it points to some valid node , put it into stack and then point to its left
is node is null , means left part is not there , so pop out from stack & point to its right node
*/

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
public:
    // Recusion
    void inorderTraversalFunction(TreeNode *root, vector<int> &inorderTrav)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversalFunction(root->left, inorderTrav);
        inorderTrav.push_back(root->val);
        inorderTraversalFunction(root->right, inorderTrav);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorderTrav;
        inorderTraversalFunction(root, inorderTrav);
        return inorderTrav;
    }

    // Iterations
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorderTrav;
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }

            else
            {
                if (st.empty())
                {
                    break;
                }

                node = st.top();
                st.pop();

                inorderTrav.push_back(node->val);
                node = node->right;
            }
        }

        return inorderTrav;
    }
};

// TC : O(N) -- traverse all nodes one time
// SC : O(N) -- recursion stack space or stack space for iteration

int main()
{

    return 0;
}