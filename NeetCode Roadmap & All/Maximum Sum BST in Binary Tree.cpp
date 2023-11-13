#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// brute force -- call validate bst for every node then sum it up it takes O(N*N)
// optimised approach
class Nodevalue
{
public:
    int sum, smallest, largest;

    Nodevalue(int sum, int smallest, int largest)
    {
        this->sum = sum;
        this->smallest = smallest;
        this->largest = largest;
    }
};

class Solution
{
    // postorder traversal
    Nodevalue maxBST(TreeNode *root, int &maxi)
    {
        // empty bst will have a sum 0
        if (root == NULL)
        {
            return {0, INT_MAX, INT_MIN};
        }

        Nodevalue left_child = maxBST(root->left, maxi);
        Nodevalue right_child = maxBST(root->right, maxi);

        int num = root->val;

        if (num > left_child.largest && num < right_child.smallest)
        {
            int node_sum = left_child.sum + right_child.sum + num;
            int node_smallest = min(num, left_child.smallest);
            int node_largest = max(num, right_child.largest);

            maxi = max(maxi, node_sum);
            return Nodevalue(node_sum, node_smallest, node_largest);
        }

        return Nodevalue(max(left_child.sum, right_child.sum), INT_MIN, INT_MAX);
    }

public:
    int maxSumBST(TreeNode *root)
    {
        int maxi = 0;
        Nodevalue obj = maxBST(root, maxi);
        return maxi;
    }
};

int main()
{

    return 0;
}