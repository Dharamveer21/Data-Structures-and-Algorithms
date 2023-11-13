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

// iterative -- put right node first then left node because of LIFO of stack
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
            traversal.push_back(node->val);
            st.pop();

            if (node->right != NULL)
            {
                st.push(node->right);
            }

            if (node->left != NULL)
            {
                st.push(node->left);
            }
        }

        return traversal;
    }
};

int main()
{

    return 0;
}