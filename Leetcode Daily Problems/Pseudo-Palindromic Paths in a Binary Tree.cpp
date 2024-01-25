#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We need to maintain a array of numbers from 1 to 9 which will store the count of numbers while
traversing the tree
It is more like a backtracking problem, while entering the child node , i need to store the count of the
num of that child then when i am coming back I will remove its count from the array .
When my node reached a NULL value means it has already met the leaf node , I will check if all elements are
having even count or only 1 element has odd count else all have even count then i will count it as my path

Approach 2 -- We will use a integer rather than an array. We will update the count of any number by togling the
bit of the integer , because we only need oddCount , so setbit at anytime is count of oddCount.
*/

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

// Approach 1
class Solution
{
protected:
    bool isLeafNode(TreeNode *root)
    {
        return (root->left == NULL && root->right == NULL);
    }

    bool isPalindrome(vector<int> &numCount)
    {
        int oddCount = 0;

        for (int ind = 1; ind <= 9; ind++)
        {
            int count = numCount[ind];
            oddCount = oddCount + (count & 1);
        }

        return (oddCount == 0 || oddCount == 1);
    }

    void pseudoPaths(TreeNode *root, vector<int> &numCount, int &numPseudoPalindromicPaths)
    {
        if (isLeafNode(root))
        {
            bool isNumCountPalindrome = isPalindrome(numCount);
            numPseudoPalindromicPaths += (isNumCountPalindrome == true);
            return;
        }

        if (root->left != NULL)
        {
            numCount[root->left->val]++;
            pseudoPaths(root->left, numCount, numPseudoPalindromicPaths);
            numCount[root->left->val]--;
        }

        if (root->right != NULL)
        {
            numCount[root->right->val]++;
            pseudoPaths(root->right, numCount, numPseudoPalindromicPaths);
            numCount[root->right->val]--;
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int numPseudoPalindromicPaths = 0;
        vector<int> numsCount(10, 0);

        numsCount[root->val]++;

        pseudoPaths(root, numsCount, numPseudoPalindromicPaths);
        return numPseudoPalindromicPaths;
    }
};

// TC : O(N) , N - number of nodes
// SC : O(H) , H -- height of tree

int main()
{

    return 0;
}