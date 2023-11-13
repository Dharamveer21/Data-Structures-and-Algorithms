#include <bits/stdc++.h>
using namespace std;

// The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself
//Normal solution is that when we use a two arrays to store the paths of the nodes while traversing them two times (one time for each) -- TC : O(N) + O(N) , SC : O(N) + O(N)
// Optimized approach would be if just check what my both child return not NULL that means i am the LCA

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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *curr = root;
        int val1 = p->val, val2 = q->val;

        while (true)
        {
            int num = curr->val;

            if ((num > val1 && num > val2))
            {
                curr = curr->left;
            }
            
            else if ((num < val1 && num < val2))
            {
                curr = curr->right;
            }

            else
            {
                break;
            }
        }

        return curr;
    }
};

int main()
{

    return 0;
}
