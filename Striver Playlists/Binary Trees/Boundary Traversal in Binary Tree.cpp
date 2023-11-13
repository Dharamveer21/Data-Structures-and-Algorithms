#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

/*Left boundary except leaf -- leaf nodes in inorder traversal -- right boundary without leaf in reverse direction*/

class Solution
{
public:
    bool is_leaf(Node *root)
    {
        return ((root->left == NULL) && (root->right == NULL));
    }

    void inorder(Node *root, vector<int> &leaf_nodes)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, leaf_nodes);

        if (is_leaf(root))
        {
            leaf_nodes.push_back(root->data);
        }

        inorder(root->right, leaf_nodes);
    }

    vector<int> boundary(Node *root)
    {

        Node *node = root;
        vector<int> leaf_nodes;
        inorder(root, leaf_nodes);

        vector<int> boundary_traversal;
        stack<int> right_traversal;

        if (root == NULL)
        {
            return boundary_traversal;
        }

        if (is_leaf(root))
        {
            boundary_traversal.push_back(root->data);
            return boundary_traversal;
        }

        boundary_traversal.push_back(root->data);

        // left boundary without leaf
        if (root->left != NULL)
        {
            node = root->left;

            while (!is_leaf(node))
            {
                boundary_traversal.push_back(node->data);

                if (node->left != NULL)
                {
                    node = node->left;
                    continue;
                }

                else if (node->right != NULL)
                {
                    node = node->right;
                }
            }
        }

        // leaf nodes
        for (int val : leaf_nodes)
        {
            boundary_traversal.push_back(val);
        }

        // right reverse traversak without leaf nodes
        if (root->right != NULL)
        {
            node = root->right;

            while (!is_leaf(node))
            {
                right_traversal.push(node->data);

                if (node->right != NULL)
                {
                    node = node->right;
                    continue;
                }

                else if (node->left != NULL)
                {
                    node = node->left;
                }
            }
        }

        while (!right_traversal.empty())
        {
            int val = right_traversal.top();
            right_traversal.pop();
            boundary_traversal.push_back(val);
        }

        return boundary_traversal;
    }
};

int main()
{

    return 0;
}