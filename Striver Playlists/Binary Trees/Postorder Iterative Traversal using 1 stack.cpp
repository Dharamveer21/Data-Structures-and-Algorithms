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

// iterative -- using 1 stack --> just push in ans then the other stack & reverse it
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        stack<TreeNode *> st;

        if (root == NULL)
        {
            return traversal;
        }

        st.push(root);

        while (!st.empty())
        {
            auto node = st.top();
            st.pop();

            traversal.push_back(node->val);

            if (node->left != NULL)
            {
                st.push(node->left);
            }

            if (node->right != NULL)
            {
                st.push(node->right);
            }
        }

        reverse(traversal.begin(), traversal.end());
        return traversal;
    }
};

int main()
{

    return 0;
}