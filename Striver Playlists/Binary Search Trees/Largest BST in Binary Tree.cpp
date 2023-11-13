#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// brute force -- call validate bst for every node then sum it up it takes O(N*N)
// optimised approach
class Nodevalue
{
public:
    int size, smallest, largest;

    Nodevalue(int size, int smallest, int largest)
    {
        this->size = size;
        this->smallest = smallest;
        this->largest = largest;
    }
};

class Solution
{
    // post order traversal
    Nodevalue LargestBSTsubtree(Node *root)
    {
        // empty tree is a bst with size 0
        if (root == NULL)
        {
            return Nodevalue(0, INT_MAX, INT_MIN);
        }

        Nodevalue left_child = LargestBSTsubtree(root->left);
        Nodevalue right_child = LargestBSTsubtree(root->right);

        int num = root->data;

        if (num > left_child.largest && num < right_child.smallest)
        {
            int node_size = left_child.size + right_child.size + 1;
            int node_smallest = left_child.smallest;
            int node_largest = right_child.largest;

            return Nodevalue(node_size, min(num, node_smallest), max(num, node_largest));
        }
         
        return Nodevalue(max(left_child.size, right_child.size), INT_MIN, INT_MAX);
    }

public:
    // largest from left & smallest for right & size of the tree
    int largestBst(Node *root)
    {
        Nodevalue obj = LargestBSTsubtree(root);
        int ans = obj.size;
        return ans;
    }
};

int main()
{

    return 0;
}