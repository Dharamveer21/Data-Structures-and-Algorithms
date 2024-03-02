#include <bits/stdc++.h>
using namespace std;

/*
Approach -- here we can use a bfs for level order traversal but we will put right child first & then left child
so , in the last after processing all nodes the last node we processed will be the leftmost node of the last
level but it will consume O(largest nodes on a level) space .

We can reduce the space complexity if we use dfs , here we will increase a variable depth & put the bottomMost
element whenever we first visit a greater depth . Here the space consumed is recursion stack space only .
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
    void depthFirstSearch(TreeNode *root, int depth, int &maxDepth, int &bottomLeftMost)
    {
        if (root == NULL)
        {
            return;
        }

        if (depth > maxDepth)
        {
            bottomLeftMost = root->val;
            maxDepth = depth;
        }
          
        depthFirstSearch(root->left, depth + 1, maxDepth, bottomLeftMost);
        depthFirstSearch(root->right, depth + 1, maxDepth, bottomLeftMost);
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        int maxDepth = -1, bottomLeftMost = root->val;
        depthFirstSearch(root, 0, maxDepth, bottomLeftMost);
        return bottomLeftMost;
    }
};

// TC : O(N)
// SC : O(H)

int main()
{

    return 0;
}