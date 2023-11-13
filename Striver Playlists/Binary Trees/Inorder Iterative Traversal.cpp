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

// iterative
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        TreeNode *node = root;
        stack<TreeNode *> st;

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

                traversal.push_back(node->val);
                node = node->right;
            }
        }

        return traversal;
    }
};

int main()
{

    return 0;
}