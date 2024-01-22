#include <bits/stdc++.h>
using namespace std;

/*
Use Slow fast pointer to get the value of the given mid value then pass leftSubtree & rightSubtree into
recursion & connect to the root which is given by slow pointer
*/

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

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

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slowPrev = NULL;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slowPrev = slow;
            slow = slow->next;
        }

        slowPrev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);

        TreeNode *leftSubtree = sortedListToBST(head);
        TreeNode *rightSubtree = sortedListToBST(slow->next);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }
};

// TC : O(N * log(N))
// SC : O(log(N)) -- stack space

int main()
{

    return 0;
}