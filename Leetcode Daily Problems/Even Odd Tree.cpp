#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we have to do the level order traversal & check the given conditions for the particular level
One important point is that for all operations we need to process the all the elements at the same level
we can use size of the queue loop for this , the size of queue is the number of elements in it of same level
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
    int assignPrev(int level)
    {
        return ((level & 1) ? (INT_MAX) : (0));
    }

    bool doesHaveCorrectParity(int curr, int level)
    {
        return ((level & 1) ? ((curr & 1) == 0) : ((curr & 1) == 1));
    }

    bool isStrictlyCorrect(int curr, int prev, int level)
    {
        return ((level & 1) ? (curr < prev) : (curr > prev));
    }

    void addChildren(TreeNode *node, queue<TreeNode *> &q)
    {
        TreeNode *leftChild = node->left;
        TreeNode *rightChild = node->right;

        if (leftChild != NULL)
        {
            q.push(leftChild);
        }

        if (rightChild != NULL)
        {
            q.push(rightChild);
        }
    }

public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        int level = -1;
        q.push(root);

        while (!q.empty())
        {
            level = level + 1;
            int size = q.size();
            int prev = assignPrev(level);

            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();

                int curr = node->val;
                int num = doesHaveCorrectParity(curr, level);
                num += isStrictlyCorrect(curr, prev, level);

                switch (num)
                {
                case 0:
                    return false;

                case 1:
                    return false;
                }

                addChildren(node, q);
                prev = curr;
            }
        }

        return true;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}