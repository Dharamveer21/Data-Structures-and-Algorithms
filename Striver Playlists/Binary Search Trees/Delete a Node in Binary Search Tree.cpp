#include <bits/stdc++.h>
using namespace std;

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

// either cut off the link of the left portion & attach the right portion to the parent of deleted node & connect the left portion to the left_most part of the right subtree
//  or vice versa

class Solution
{
public:
    void join(TreeNode *child)
    {
        TreeNode *right_most = child->left;

        while (right_most->right != NULL)
        {
            right_most = right_most->right;
        }

        right_most->right = child->right;
    }

    pair<TreeNode *, TreeNode *> search(TreeNode *root, int key, int &direction)
    {
        TreeNode *par = NULL, *child = root;

        while (true)
        {
            if ((child == NULL) || (child->val == key))
            {
                break;
            }

            if (child->val > key)
            {
                par = child;
                child = child->left;
                direction = -1;
            }

            else
            {
                par = child;
                child = child->right;
                direction = 1;
            }
        }

        return {par, child};
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        int dir = 0;
        auto node = search(root, key, dir);

        TreeNode *par = node.first;
        TreeNode *child = node.second;
        TreeNode *ans = root;

        if (child == NULL)
        {
            return ans;
        }

        if (par == NULL)
        {
            // root is to be deleted -- join the right subtree to the rightmost child of left subtree
            if (child->left == NULL)
            {
                ans = child->right;
            }

            else if (child->right == NULL)
            {
                ans = child->left;
            }

            else
            {
                join(child);
                ans = child->left;
            }

            delete (child);
            return ans;
        }

        else
        {
            // child is left of the parent
            if (dir == -1)
            {
                if (child->left == NULL)
                {
                    par->left = child->right;
                }

                else if (child->right == NULL)
                {
                    par->left = child->left;
                }

                else
                {
                    par->left = child->left;
                    join(child);
                }

                delete (child);
            }

            else
            {
                if (child->left == NULL)
                {
                    par->right = child->right;
                }

                else if (child->right == NULL)
                {
                    par->right = child->left;
                }

                else
                {
                    par->right = child->left;
                    join(child);
                }

                delete (child);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}