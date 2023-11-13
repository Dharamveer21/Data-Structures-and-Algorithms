#include <bits/stdc++.h>
using namespace std;

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

// without storing the inorder -- so we need to do it in Tc : O(1) on average , SC : O(H) on  average
// we will use stack
class BSTIterator
{
    stack<TreeNode *> st;

    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        pushAll(node->right);
        int num = node->val;
        return num;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};

int main()
{

    return 0;
}