#include <bits/stdc++.h>
using namespace std;

/*Change the links according to the preorder traversal*/
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive solution
class Solution
{
public:
    // Lets suppose last_flatten will point to the latest flatten node
    void flatten_tree(TreeNode *node, TreeNode *&last_flatten)
    {
        if (node == NULL)
        {
            return;
        }

        flatten_tree(node->right, last_flatten);
        flatten_tree(node->left, last_flatten);

        node->right = last_flatten;
        node->left = NULL;
        last_flatten = node;
    }

    void flatten(TreeNode *root)
    {
        TreeNode *last_flatten = NULL;
        flatten_tree(root, last_flatten);
    }
};

// Iterative solution using stack
class Solution
{
public:
    // Lets point every node to its left child
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node->right != NULL)
            {
                st.push(node->right);
            }

            if (node->left != NULL)
            {
                st.push(node->left);
            }

            if (!st.empty())
            {
                node->right = st.top();
            }

            node->left = NULL;
        }
    }
};

// In O(1) space using morris traversal
// The last in pre order of left subtree should be connected to right of the node
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *last_flatten = curr->left;

                while (last_flatten->right != NULL)
                {
                    last_flatten = last_flatten->right;
                }

                last_flatten->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};

int main()
{

    return 0;
}