#include <bits/stdc++.h>
using namespace std;

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

// iterative -- using 2 stacks
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        stack<TreeNode *> st;
        stack<int> post_traversal;

        st.push(root);

        if (root == NULL)
        {
            return traversal;
        }

        while (!st.empty())
        {
            auto node = st.top();
            st.pop();

            post_traversal.push(node->val);

            if (node->left != NULL)
            {
                st.push(node->left);
            }

            if (node->right != NULL)
            {
                st.push(node->right);
            }
        }

        while (!post_traversal.empty())
        {
            auto num = post_traversal.top();
            traversal.push_back(num);
            post_traversal.pop();
        }

        return traversal;
    }
};

int main()
{

    return 0;
}