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

// Depth First Search & Implementation
class Solution
{
protected:
    TreeNode *addingNewRowAtParticularDepth(TreeNode *root, int &val, int &insertionDepth, int currDepth)
    {
        if (root == NULL)
            return NULL;

        if (currDepth == insertionDepth - 1)
        {
            TreeNode *leftSubtree = root->left;
            TreeNode *rightSubtree = root->right;

            TreeNode *newLeftNode = new TreeNode(val);
            TreeNode *newRightNode = new TreeNode(val);

            root->left = newLeftNode;
            root->right = newRightNode;

            newLeftNode->left = leftSubtree;
            newRightNode->right = rightSubtree;

            return root;
        }

        addingNewRowAtParticularDepth(root->left, val, insertionDepth, currDepth + 1);
        addingNewRowAtParticularDepth(root->right, val, insertionDepth, currDepth + 1);

        return root;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *newRootNode;

        if (depth == 1)
        {
            newRootNode = new TreeNode(val);
            newRootNode->left = root;

            return newRootNode;
        }

        newRootNode = addingNewRowAtParticularDepth(root, val, depth, 1);
        return newRootNode;
    }
};

// TC : O(N) -- N is total nodes
// SC : O(2^D) -- D is given depth

// Breadth First Search & Implementation
class Solution
{
protected:
    void addChildrenToQueue(TreeNode *&root, queue<TreeNode *> &q)
    {
        TreeNode *leftChild = root->left;
        TreeNode *rightChild = root->right;

        if (leftChild != NULL)
            q.push(leftChild);

        if (rightChild != NULL)
            q.push(rightChild);
    }

    TreeNode *addingNewRowAtParticularDepth(TreeNode *root, int &val, int &insertionDepth)
    {
        int depthOfCurrentRow = 0;
        queue<TreeNode *> queueForBreadthFirstSearch;
        queueForBreadthFirstSearch.push(root);

        while (!queueForBreadthFirstSearch.empty())
        {
            depthOfCurrentRow = depthOfCurrentRow + 1;
            int size = queueForBreadthFirstSearch.size();

            while (size--)
            {
                TreeNode *currNode = queueForBreadthFirstSearch.front();
                queueForBreadthFirstSearch.pop();

                addChildrenToQueue(currNode, queueForBreadthFirstSearch);

                if (depthOfCurrentRow == insertionDepth - 1)
                {
                    TreeNode *leftSubtree = currNode->left;
                    TreeNode *rightSubtree = currNode->right;

                    TreeNode *newLeftNode = new TreeNode(val);
                    TreeNode *newRightNode = new TreeNode(val);

                    currNode->left = newLeftNode;
                    currNode->right = newRightNode;

                    newLeftNode->left = leftSubtree;
                    newRightNode->right = rightSubtree;
                }
            }

            if (depthOfCurrentRow == insertionDepth - 1)
                return root;
        }

        return root;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *newRootNode;

        if (depth == 1)
        {
            newRootNode = new TreeNode(val);
            newRootNode->left = root;

            return newRootNode;
        }

        newRootNode = addingNewRowAtParticularDepth(root, val, depth);
        return newRootNode;
    }
};

// TC : O(N) -- N is total nodes
// SC : O(2^D) -- D is given depth

int main()
{

    return 0;
}