#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Use BFS for level order traversal & while traversing calculate the maximum element
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
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> rowLargest;

        if (root == NULL)
        {
            return rowLargest;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int rowLength = q.size();
            int rowMax = INT_MIN;

            for (int i = 0; i < rowLength; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int val = node->val;
                rowMax = max(rowMax, val);

                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }

            rowLargest.push_back(rowMax);
        }

        return rowLargest;
    }
};

// TC : O(2 ^ (rows)) -- total nodes in the tree
// SC : O(2 ^ (rows-1) + rows) -- maximum nodes at a time in the queue , which is last level

int main()
{

    return 0;
}