#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We use recursive approach in this problem we can match the root node & left subtree & right subtree
*/

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

class Solution
{
protected:
    bool isTheTwoTreesSame(TreeNode *root1, TreeNode *root2)
    {
        int cnt = ((root1 == NULL) + (root2 == NULL));

        switch (cnt)
        {
        case 0:
        {
            bool areRootsEqual = (root1->val == root2->val);
            bool isLeftSubtreeSame = isTheTwoTreesSame(root1->left, root2->left);
            bool isRightSubtreeSame = isTheTwoTreesSame(root1->right, root2->right);
            return (areRootsEqual && isLeftSubtreeSame && isRightSubtreeSame);
        }

        case 1:
            return false;
        }

        return true;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return isTheTwoTreesSame(p, q);
    }
};

// TC : O(N) , N -- number of nodes
// SC : O(H) , H -- height of tree

int main()
{

    return 0;
}