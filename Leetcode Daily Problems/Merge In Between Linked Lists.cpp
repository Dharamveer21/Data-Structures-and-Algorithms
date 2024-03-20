#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here in this problem we just have to find the correct pointer of the location (a-1) & (b+1) in list1
and the current (a-1) to head of list2 and tail of list2 to (b+1) . Finally return the head of list1 . Due to
the given constraints in the problem 1 <= a <= b < list1.size() - 1 . Which means we always have nodes (a-1) and
(b+1) so we just have to connect them to list2 and return the head of list1 in the answer .

N -- size of list 1 and M -- size of list 2
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
    ListNode *nodeAtParticularPosition(ListNode *&list, int pos)
    {
        int index = 0;
        ListNode *curr = list;

        while (index < pos && curr->next != NULL)
        {
            curr = curr->next;
            index++;
        }

        return curr;
    }

public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        const int INF = 1e5 + 10;
        ListNode *headOfMergedList;

        ListNode *start1 = nodeAtParticularPosition(list1, a - 1);
        ListNode *end1 = nodeAtParticularPosition(list1, b + 1);

        ListNode *start2 = nodeAtParticularPosition(list2, 0);
        ListNode *end2 = nodeAtParticularPosition(list2, INF);

        start1->next = start2;
        end2->next = end1;

        headOfMergedList = list1;
        return headOfMergedList;
    }
};

// TC : O(N + M)
// SC : O(1)

int main()
{

    return 0;
}