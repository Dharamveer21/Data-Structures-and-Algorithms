#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL, *right = NULL;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// one way is to store the inorder & preorder of the tree in a string seprated by a space then in deserialize it using buildtree algorithm
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }

        string str = "";
        char ch = ',';

        // level order traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node != root)
            {
                str.push_back(ch);
            }

            if (node == NULL)
            {
                str.push_back('#');
                continue;
            }

            str.append(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');

            if (str == "#")
            {
                node->left = NULL;
            }

            else
            {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');

            if (str == "#")
            {
                node->right = NULL;
            }

            else
            {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}