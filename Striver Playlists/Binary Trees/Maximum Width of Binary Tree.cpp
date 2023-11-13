#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

/*Index the tree in level order traversing when every child has 2 nodes*/
/*use indexing for children as left_child -- (2*i + 1) && right_child -- (2*i+2) where i is the index of parent node*/
/*we will start the indexing for every level from 0 to prevent overflow*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        long long width = 1;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            long long size = q.size();
            long long mini_ind = q.front().second;
            long long first_ind, last_ind;

            for (long long i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                TreeNode *node = it.first;
                long long curr_ind = it.second - mini_ind;

                if (i == 0)
                {
                    first_ind = curr_ind;
                }

                if (i == size - 1)
                {
                    last_ind = curr_ind;
                }

                if (node->left != NULL)
                {
                    q.push({node->left, 2 * curr_ind + 1});
                }

                if (node->right != NULL)
                {
                    q.push({node->right, 2 * curr_ind + 2});
                }
            }

            width = max(width, last_ind - first_ind + 1);
        }

        return (int)width;
    }
};

int main()
{

    return 0;
}