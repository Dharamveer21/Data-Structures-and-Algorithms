#include <bits/stdc++.h>
using namespace std;

/*
approach -- we will sort the queries according to second element of queries & then input in tries accordingly
finlly arrange the ans in order of the input queries .
*/

class Node
{
private:
    Node *links[2];

public:
    bool isContains(int bit)
    {
        return (this->links[bit] != NULL);
    }

    void PutBit(int bit, Node *node)
    {
        this->links[bit] = node;
    }

    Node *next(int bit)
    {
        return (this->links[bit]);
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *curr = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);

            if (!(curr->isContains(bit)))
            {
                curr->PutBit(bit, new Node());
            }

            curr = curr->next(bit);
        }
    }

    int Max_Xor(int num)
    {
        Node *curr = root;
        int max_xor = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            int req = 1 - bit;

            if (curr->isContains(req))
            {
                max_xor = (max_xor | (1 << i));
                curr = curr->next(req);
            }

            else
            {
                curr = curr->next(bit);
            }
        }

        return max_xor;
    }
};

class Solution
{
private:
    void insert_query(int start, int end, vector<int> &nums, Trie *&trie, int &cnt)
    {
        for (int i = start; i < end; i++)
        {
            cnt++;
            trie->insert(nums[i]);
        }
    }

public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int ind = 0, cnt = 0;
        Trie *trie = new Trie();
        vector<int> ans(queries.size());
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> order_query;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int q = i;
                int x = queries[i][0];
                int m = queries[i][1];

                order_query.push({{m, x}, q});
            }
        }

        while (!order_query.empty())
        {
            pair<pair<int, int>, int> node = order_query.top();
            order_query.pop();

            int q = node.second;
            int x = node.first.second;
            int m = node.first.first;

            int start = ind;
            int end = (upper_bound(nums.begin(), nums.end(), m) - nums.begin());
            insert_query(start, end, nums, trie, cnt);

            int xor_val = ((cnt == 0) ? -1 : trie->Max_Xor(x));
            ans[q] = xor_val;
            ind = end;
        }

        return ans;
    }
};
