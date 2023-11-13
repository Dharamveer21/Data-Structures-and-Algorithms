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
private:
    stack<TreeNode *> st;
    bool isReverse;

    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);

            if (isReverse)
            {
                root = root->right;
            }

            else
            {
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool reverse)
    {
        isReverse = reverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();

        if (isReverse)
        {
            pushAll(node->left);
        }

        else
        {
            pushAll(node->right);
        }

        int num = node->val;
        return num;
    }
};

// use next & before stacks to apply the method of two sum in sorted arr using pointers start & end
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator left_child(root, false);
        BSTIterator right_child(root, true);

        int num1 = left_child.next();
        int num2 = right_child.next();

        while (num1 < num2)
        {
            if (num1 + num2 == k)
            {
                return true;
            }

            if ((num1 + num2) < (k))
            {
                num1 = left_child.next();
            }

            else
            {
                num2 = right_child.next();
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}