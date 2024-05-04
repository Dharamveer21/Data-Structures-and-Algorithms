#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use pre-order traversal to find the leaf nodes in particular order from left to right
then we compare the leafnodes values & check if there are equal or not

Here morris traversal cannot be used , because it connects the right pointer of the leaf node to its root
So , it no longer points to NULL --> so our function will not going to identify it as Leaf Node
*/

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

class Solution
{
protected:
    bool isLeafNode(TreeNode *node)
    {
        return (node->left == NULL && node->right == NULL);
    }

    void leafValueSequence(TreeNode *root, vector<int> &leafVal)
    {
        if (root == NULL)
        {
            return;
        }

        leafValueSequence(root->left, leafVal);

        if (isLeafNode(root))
        {
            int value = root->val;
            leafVal.push_back(value);
        }

        leafValueSequence(root->right, leafVal);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leafValueSeq1;
        vector<int> leafValueSeq2;

        leafValueSequence(root1, leafValueSeq1);
        leafValueSequence(root2, leafValueSeq2);

        return (leafValueSeq1 == leafValueSeq2);
    }
};

// TC : O(N + N) = O(N) -- traversal of whole tree & comparision of leafValue Arrays
// SC : O(N) -- leaf value arrays

int main()
{

    return 0;
}