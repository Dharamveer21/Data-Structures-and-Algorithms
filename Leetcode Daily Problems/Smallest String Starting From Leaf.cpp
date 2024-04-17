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
    bool isLeafNode(TreeNode *root)
    {
        return (root->left == NULL && root->right == NULL);
    }

    void smallestStringFromLeafToRoot(TreeNode *root, string &currString, string &smallestString)
    {
        if (root == NULL)
            return;
        
        int value = root->val;
        char ch = 'a' + value;
        currString.push_back(ch);
        
        if (isLeafNode(root))
        {
            reverse(currString.begin(), currString.end());
            smallestString = ((smallestString == "" || currString < smallestString) ? currString : smallestString);
            reverse(currString.begin(), currString.end());
        }
        
        smallestStringFromLeafToRoot(root->left, currString, smallestString);
        smallestStringFromLeafToRoot(root->right, currString, smallestString);
        currString.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string currString, smallestString;
        smallestStringFromLeafToRoot(root, currString, smallestString);

        return smallestString;
    }
};

// TC : O(N) -- N is nodes in tree
// SC : O(H) -- H is height of tree

int main()
{

    return 0;
}