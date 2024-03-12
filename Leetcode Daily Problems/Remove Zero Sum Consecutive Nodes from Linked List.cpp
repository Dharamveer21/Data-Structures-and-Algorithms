#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can solve this problem in two loops but it is brute force and takes O(n2) complexity , we can use
a better approach -- here we can use a hashMap to store the prefix sum upto every node . Whenever the prefix sum
we got is also present in the map means the whole sum of the segment is 0 , because anything added to zero
remains same . Hence we connect the node (whose prefix sum is same as curr Prefix sum) in the map with the next
of currNode (end of the curr Segment who sum is 0) & remove the entries of the segment from map . Here we need
to keep in mind that the head can also be removed , hence we will take a dummy node in start & takes its sum 0.
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

class Solution
{
protected:
    void removeEntries(ListNode *start, ListNode *end, int cummulativeSum, unordered_map<int, ListNode *> &prefixSum)
    {
        ListNode *curr = start;

        while (curr != end)
        {
            int nodeValue = curr->val;
            curr = curr->next;

            cummulativeSum += nodeValue;
            prefixSum.erase(cummulativeSum);
        }
    }

public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0);
        unordered_map<int, ListNode *> prefixSum;

        dummyHead->next = head;
        prefixSum.insert({0, dummyHead});

        ListNode *curr = head;
        int cummulativeSum = 0;

        while (curr != NULL)
        {
            int nodeValue = curr->val;
            cummulativeSum += nodeValue;

            if (prefixSum.find(cummulativeSum) != prefixSum.end())
            {
                ListNode *node = prefixSum[cummulativeSum];
                ListNode *start = node->next;
                ListNode *end = curr;

                node->next = curr->next;
                removeEntries(start, end, cummulativeSum, prefixSum);
            }

            else
            {
                prefixSum.insert({cummulativeSum, curr});
            }

            curr = curr->next;
        }

        head = dummyHead->next;
        return head;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}