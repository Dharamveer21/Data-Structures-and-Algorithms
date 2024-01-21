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
    void convertBSTIntoSortedLL(Node *root, Node *&head)
    {
        if (root == NULL)
        {
            return;
        }

        convertBSTIntoSortedLL(root->right, head);

        root->right = head;

        if (head != NULL)
        {
            head->left = root;
        }

        head = root;

        convertBSTIntoSortedLL(root->left, head);
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

    int countNodesInLL(Node *&head)
    {
        int nodeCnt = 0;
        Node *curr = head;

        while (curr != NULL)
        {
            nodeCnt++;
            curr = curr->right;
        }

        return nodeCnt;
    }

    Node *convertSortedLLIntoBST(Node *&headLL, int nodeCnt)
    {
        if (nodeCnt <= 0 || headLL == NULL)
        {
            return NULL;
        }

        Node *leftSubtree = convertSortedLLIntoBST(headLL, nodeCnt / 2);

        Node *root = headLL;
        root->left = leftSubtree;
        headLL = headLL->right;

        Node *rightSubtree = convertSortedLLIntoBST(headLL, nodeCnt - nodeCnt / 2 - 1);
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

                if (prev->left == NULL)
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
        Node *headLL1 = NULL, *headLL2 = NULL;

        convertBSTIntoSortedLL(root1, headLL1);
        convertBSTIntoSortedLL(root2, headLL2);

        Node *headLL = mergeSortedLL(headLL1, headLL2);

        int nodeCnt = countNodesInLL(headLL);
        Node *root = convertSortedLLIntoBST(headLL, nodeCnt);

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