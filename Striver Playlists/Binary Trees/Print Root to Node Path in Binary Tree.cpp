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
    string convert_to_string(vector<int> &path)
    {
        int n = path.size();

        string str;
        char ch1 = '-', ch2 = '>';

        for (int i = 0; i < n - 1; i++)
        {
            int num = path[i];
            string str1 = to_string(num);

            for (int j = 0; j < str1.size(); j++)
            {
                str.push_back(str1[j]);
            }
            
            str.push_back(ch1);
            str.push_back(ch2);
        }

        string str2 = to_string(path[n - 1]);

        for (int i = 0; i < str2.size(); i++)
        {
            str.push_back(str2[i]);
        }

        return str;
    }

    // Path to all leaf nodes
    void path_finder(TreeNode *root, vector<int> &path, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            string str = convert_to_string(path);
            ans.push_back(str);
            return;
        }

        if (root->left != NULL)
        {
            int num = root->left->val;
            path.push_back(num);
            path_finder(root->left, path, ans);
            path.pop_back();
        }

        if (root->right != NULL)
        {
            int num = root->right->val;
            path.push_back(num);
            path_finder(root->right, path, ans);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> ans;

        path.push_back(root->val);
        path_finder(root, path, ans);
        return ans;
    }
};

// Path from root to node B in Tree A
bool path_finder(TreeNode *root, vector<int> &path, int dest)
{
    if (root->val == dest)
    {
        return true;
    }

    if (root->left != NULL)
    {
        path.push_back(root->left->val);

        if (path_finder(root->left, path, dest))
        {
            return true;
        }

        path.pop_back();
    }

    if (root->right != NULL)
    {
        path.push_back(root->right->val);

        if (path_finder(root->right, path, dest))
        {
            return true;
        }

        path.pop_back();
    }

    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> path;
    path.push_back(A->val);
    path_finder(A, path, B);
    return path;
}

int main()
{

    return 0;
}