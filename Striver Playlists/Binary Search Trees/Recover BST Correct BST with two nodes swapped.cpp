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

// brute force -- store the inorder & then sort the value -- it will be the real inorder just do inroder traversal & compare with simulatneous nodes just look at the two diifernt values & swap them
// TC : O(2*N + N*logn) && SC : O(N)

// Optimised approach -- first store the first vilation & its parent & the second valiation
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL, *middle = NULL, *prev = NULL, *last = NULL;

        // morris traversal in O(1) space
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if ((prev != NULL) && (curr->val < prev->val))
                {
                    if (first == NULL)
                    {
                        first = prev;
                        middle = curr;
                    }

                    else
                    {
                        last = curr;
                    }
                }

                prev = curr;
                curr = curr->right;
            }

            else
            {
                TreeNode *right_most = curr->left;

                while (right_most->right != NULL && right_most->right != curr)
                {
                    right_most = right_most->right;
                }

                if (right_most->right == NULL)
                {
                    right_most->right = curr;
                    curr = curr->left;
                }

                else
                {
                    if ((prev != NULL) && (curr->val < prev->val))
                    {
                        if (first == NULL)
                        {
                            first = prev;
                            middle = curr;
                        }

                        else
                        {
                            last = curr;
                        }
                    }

                    prev = curr;
                    right_most->right = NULL;
                    curr = curr->right;
                }
            }
        }

        if (last == NULL)
        {
            int num1 = first->val;
            int num2 = middle->val;

            first->val = num2;
            middle->val = num1;
        }

        else
        {
            int num1 = first->val;
            int num2 = last->val;

            first->val = num2;
            last->val = num1;
        }
    }
};

int main()
{

    return 0;
}