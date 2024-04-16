#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Depth First Search
class Solution
{
protected:
    bool isLeafNode(TreeNode *node)
    {
        return (node->left == NULL && node->right == NULL);
    }

    int sumOfNumbersFromRootToLeaf(TreeNode *root, int currNum)
    {
        int totalSum = 0;

        if (root == NULL)
            return totalSum;

        int valueOfNode = root->val;
        int newNum = currNum * 10 + valueOfNode;

        totalSum += sumOfNumbersFromRootToLeaf(root->left, newNum);
        totalSum += sumOfNumbersFromRootToLeaf(root->right, newNum);

        totalSum = ((isLeafNode(root)) ? newNum : totalSum);
        return totalSum;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int totalSum = sumOfNumbersFromRootToLeaf(root, 0);
        return totalSum;
    }
};

// TC : O(N) -- N is nodes of tree
// SC : O(H) -- H is height of tree

int main()
{

    return 0;
}