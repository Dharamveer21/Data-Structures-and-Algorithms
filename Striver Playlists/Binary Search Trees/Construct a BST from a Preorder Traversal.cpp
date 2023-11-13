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

// Method 1 -- Brute force using it we can determine the position of each node each time , it will take O(N*N) time
// Method 2 -- sort the preorder & it will be inorder so we can easily construct an unique binary tree using preorder & inorder -- O(N*logN)
// Method 3 -- we will use range for each root -- O(3*N)

// as it is preorder so we have root -- left -- right , so we first try a root then its on left part then on right part .
class Solution
{
public:
    TreeNode *build(int &ind, int bound, vector<int> &order)
    {
        if (ind == order.size() || order[ind] > bound)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(order[ind++]);
        root->left = build(ind, root->val, order);
        root->right = build(ind, bound, order);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int ind = 0;
        return build(ind, INT_MAX, preorder);
    }
};

int main()
{

    return 0;
}