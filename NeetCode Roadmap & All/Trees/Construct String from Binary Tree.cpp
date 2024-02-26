#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use recursion , but there are two important conditions , 1st one is when 
the root node has left non NULL , then recursion calls for left child , 2nd one is 
right child is not null and left child is null then recursion runs for left child .
In 2nd case we have to insert empty brackets so we again call recursion base case will 
be when root is NULL it returns
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
    void makeString(TreeNode *root, string &str)
    {
        if (root == NULL)
        {
            return;
        }

        int num = root->val;
        string strnum = to_string(num);

        for (int i = 0; i < strnum.length(); i++)
        {
            char ch = strnum[i];
            str.push_back(ch);
        }

        if ((root->left != NULL) || (root->left == NULL && root->right != NULL))
        {
            str.push_back('(');
            makeString(root->left, str);
            str.push_back(')');
        }

        if (root->right != NULL)
        {
            str.push_back('(');
            makeString(root->right, str);
            str.push_back(')');
        }
    }

    string tree2str(TreeNode *root)
    {
        string ans;
        makeString(root, ans);
        return ans;
    }
};

// TC : O(N) -- traverse all nodes
// SC : O(N) -- all nodes & corresponding paranthesis in string

int main()
{
    
    return 0;
}