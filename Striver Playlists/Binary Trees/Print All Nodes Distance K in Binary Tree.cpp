#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    void mark_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root->left != NULL)
        {
            parent[root->left] = root;
            mark_parent(root->left, parent);
        }
         
        if (root->right != NULL)
        {
            parent[root->right] = root;
            mark_parent(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        vector<int> ans;

        parent[root] = NULL;
        vis[target] = true;
        int des = 0;

        mark_parent(root, parent);
        q.push(target);

        while (!q.empty())
        {
            int size = q.size();

            if (des == k)
            {
                break;
            }

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if (node->right != NULL && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if (parent[node] != NULL && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }

            des++;
        }

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            ans.push_back(node->val);
        }

        return ans;
    }
};

int main()
{

    return 0;
}