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

/*Count nodes during inroder traversal */
/*use morris traversal to do it in O(1) space*/
/*Inorder is always sorted*/

// recusive
class Solution
{
public:
    void inorder_traversal(TreeNode *root, int &k, int &cnt, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder_traversal(root->left, k, cnt, ans);
        cnt++;

        if (cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder_traversal(root->right, k, cnt, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0, ans = -1;
        inorder_traversal(root, k, cnt, ans);
        return ans;
    }
};

// morris
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0, ans = 0;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                cnt++;

                if (cnt == k)
                {
                    ans = curr->val;
                    break;
                }

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
                    cnt++;

                    if (cnt == k)
                    {
                        ans = curr->val;
                        break;
                    }

                    right_most->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}
