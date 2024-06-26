#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL, *tail = NULL;
        int numberOfLists = lists.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // insert first node of each list
        for (int ind = 0; ind < numberOfLists; ind++)
        {
            ListNode *curr = lists[ind];

            if (curr == NULL)
            {
                continue;
            }

            int num = curr->val;
            minHeap.push({num, ind});
        }

        while (!minHeap.empty())
        {
            pair<int, int> nodePointer = minHeap.top();
            minHeap.pop();

            int num = nodePointer.first;
            int index = nodePointer.second;

            ListNode *curr = lists[index];
            curr = curr->next;

            if (curr != NULL)
            {
                int val = curr->val;
                minHeap.push({val, index});
                lists[index] = curr;
            }

            ListNode *newNode = new ListNode(num);

            if (head != NULL)
            {
                tail->next = newNode;
                tail = newNode;
                continue;
            }

            head = newNode;
            tail = newNode;
        }

        return head;
    }
};

// K -- number of lists & N -- average size of each list
// TC : O(K * N * log(K)) 
// SC : O(K * N + K) = O(K * N)

int main()
{

    return 0;
}