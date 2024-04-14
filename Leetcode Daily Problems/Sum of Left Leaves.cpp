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

// Tree Traversal with parent
class Solution
{
protected:
    bool isNodeLeafAndLeftChildOfParent(TreeNode *curr, TreeNode *par)
    {
        bool isNodeLeaf = (curr->left == NULL && curr->right == NULL);
        bool isLeafNodeLeftChild = (isNodeLeaf && (par != NULL && par->left == curr));

        return isLeafNodeLeftChild;
    }

    int sumOfLeftLeafNodes(TreeNode *curr, TreeNode *par)
    {
        if (curr == NULL)
            return 0;

        bool isNodeLeafAndLeftChild = isNodeLeafAndLeftChildOfParent(curr, par);
        int sumOfLeftLeafNodesOfTree = ((isNodeLeafAndLeftChild == true) ? (curr->val) : (0));

        int sumOfLeftLeafNodesOfLeftSubtree = sumOfLeftLeafNodes(curr->left, curr);
        int sumOfLeftLeafNodesOfRightSubtree = sumOfLeftLeafNodes(curr->right, curr);

        sumOfLeftLeafNodesOfTree += sumOfLeftLeafNodesOfLeftSubtree + sumOfLeftLeafNodesOfRightSubtree;
        return sumOfLeftLeafNodesOfTree;
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sumOfLeftLeafNodesOfTree = sumOfLeftLeafNodes(root, NULL);
        return sumOfLeftLeafNodesOfTree;
    }
};

// TC : O(N) -- N is number of nodes
// SC : O(H) -- H is height of tree

// Tree Traversal with isLeft binary variable
class Solution
{
protected:
    bool isLeafNode(TreeNode *curr)
    {
        return (curr->left == NULL && curr->right == NULL);
    }

    int sumOfLeftLeafNodes(TreeNode *curr, bool isLeftChild)
    {
        if (curr == NULL)
            return 0;

        bool isNodeLeafAndLeft = (isLeafNode(curr) && isLeftChild);
        int sumOfLeftLeafNodesOfTree = ((isNodeLeafAndLeft == true) ? (curr->val) : (0));

        int sumOfLeftLeafNodesOfLeftSubtree = sumOfLeftLeafNodes(curr->left, true);
        int sumOfLeftLeafNodesOfRightSubtree = sumOfLeftLeafNodes(curr->right, false);

        sumOfLeftLeafNodesOfTree += sumOfLeftLeafNodesOfLeftSubtree + sumOfLeftLeafNodesOfRightSubtree;
        return sumOfLeftLeafNodesOfTree;
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sumOfLeftLeafNodesOfTree = sumOfLeftLeafNodes(root, false);
        return sumOfLeftLeafNodesOfTree;
    }
};

// TC : O(N) -- N is number of nodes
// SC : O(H) -- H is height of tree

int main()
{

    return 0;
}