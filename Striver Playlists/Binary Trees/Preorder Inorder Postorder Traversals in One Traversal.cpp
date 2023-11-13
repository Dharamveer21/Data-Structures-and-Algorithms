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

// Pre In Post order all traversal in one code
class Solution
{
public:
    vector<int> preinpostorderTraversal(TreeNode *root)
    {
        vector<int> preorder_traversal, inorder_traversal, postorder_traversal;
        stack<pair<TreeNode *, int>> st;

        if (root == NULL)
        {
            return preorder_traversal;
            return inorder_traversal;
            return postorder_traversal;
        }

        st.push({root, 1});

        while (!st.empty())
        {
            auto node_num = st.top();
            st.pop();

            TreeNode *node = node_num.first;
            int num = node_num.second;

            if (num == 1)
            {
                preorder_traversal.push_back(node->val);
                num = num + 1;
                st.push({node, num});

                if (node->left != NULL)
                {
                    st.push({node->left, 1});
                }

                continue;
            }

            if (num == 2)
            {
                inorder_traversal.push_back(node->val);
                num = num + 1;
                st.push({node, num});

                if (node->right != NULL)
                {
                    st.push({node->right, 1});
                }

                continue;
            }

            postorder_traversal.push_back(node->val);
        }

        return preorder_traversal;
        return inorder_traversal;
        return postorder_traversal;
    }
};

int main()
{

    return 0;
}