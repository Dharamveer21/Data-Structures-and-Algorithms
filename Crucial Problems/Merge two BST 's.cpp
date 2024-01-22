#include <bits/stdc++.h>
using namespace std;

/*
Approach -- there are three steps of this problem
1. Convert two BSTs into two sorted Linked Lists
2. merge Two sorted Linked List
3. Convert sorted Linked List into BST
4. Store the Inorder Traversal of BST
*/

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

class Solution
{
protected:
    pair<Node *, Node *> convertBSTIntoSortedLL(Node *root)
    {
        if (root == NULL)
        {
            return {NULL, NULL};
        }

        pair<Node *, Node *> leftSubtree = convertBSTIntoSortedLL(root->left);
        pair<Node *, Node *> rightSubtree = convertBSTIntoSortedLL(root->right);

        Node *leftHead = leftSubtree.first, *leftTail = leftSubtree.second;
        Node *rightHead = rightSubtree.first, *rightTail = rightSubtree.second;

        if (leftHead == NULL)
        {
            root->right = rightHead;

            if (rightHead != NULL)
            {
                rightHead->left = root;
                return {root, rightTail};
            }

            return {root, root};
        }

        else
        {
            leftTail->right = root;
            root->left = leftTail;

            root->right = rightHead;

            if (rightHead != NULL)
            {
                rightHead->left = root;
                return {leftHead, rightTail};
            }
        }

        return {leftHead, root};
    }

    Node *mergeSortedLL(Node *headLL1, Node *headLL2)
    {
        Node *head = NULL;
        Node *tail = NULL;

        Node *curr1 = headLL1;
        Node *curr2 = headLL2;

        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->data <= curr2->data)
            {
                if (head == NULL)
                {
                    head = curr1;
                    tail = head;

                    curr1 = curr1->right;
                }

                else
                {
                    tail->right = curr1;
                    curr1->left = tail;

                    tail = curr1;
                    curr1 = curr1->right;
                }
            }

            else
            {
                if (head == NULL)
                {
                    head = curr2;
                    tail = curr2;

                    curr2 = curr2->right;
                }

                else
                {
                    tail->right = curr2;
                    curr2->left = tail;

                    tail = curr2;
                    curr2 = curr2->right;
                }
            }
        }

        while (curr1 != NULL)
        {
            if (head == NULL)
            {
                head = curr1;
                tail = curr1;
                curr1 = curr1->right;
            }

            else
            {
                tail->right = curr1;
                curr1->left = tail;

                tail = curr1;
                curr1 = curr1->right;
            }
        }

        while (curr2 != NULL)
        {
            if (head == NULL)
            {
                head = curr2;
                tail = curr2;
                curr2 = curr2->right;
            }

            else
            {
                tail->right = curr2;
                curr2->left = tail;

                tail = curr2;
                curr2 = curr2->right;
            }
        }

        return head;
    }

    Node *convertSortedLLIntoBST(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->right == NULL)
        {
            head->left = NULL;
            return head;
        }

        Node *fast = head;
        Node *slow = head;
        Node *slowPrev = NULL;

        while (fast != NULL && fast->right != NULL)
        {
            fast = fast->right->right;
            slowPrev = slow;
            slow = slow->right;
        }

        Node *root = slow;
        slowPrev->right = NULL;

        Node *leftSubtree = convertSortedLLIntoBST(head);
        Node *rightSubtree = convertSortedLLIntoBST(slow->right);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }

    void inorderTraversal(Node *root, vector<int> &inorder)
    {
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }

            else
            {
                Node *prev = curr->left;

                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
    }

public:
    vector<int> merge(Node *root1, Node *root2)
    {
        Node *headLL1 = convertBSTIntoSortedLL(root1).first;
        Node *headLL2 = convertBSTIntoSortedLL(root2).first;

        Node *headLL = mergeSortedLL(headLL1, headLL2);
        Node *root = convertSortedLLIntoBST(headLL);

        vector<int> inorder;
        inorderTraversal(root, inorder);

        return inorder;
    }
};

// TC : O(N1  + N2) -- Number of nodes in Tree1 is N1 & number of nodes in Tree2 is N2
// SC : O(max(H1 + H2)) -- H is height of binary tree , it is recursion stack space

int main()
{

    return 0;
}