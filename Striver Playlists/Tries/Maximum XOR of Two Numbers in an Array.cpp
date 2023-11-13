#include <bits/stdc++.h>
using namespace std;

/*
In order to solve that problem we need to solve another simple problem - Given the array of numbers & a number x find the max value of (arr[i]^x)

we insert all numbers into trie & insert them in terms of binary numbers

take x & find the max no. from array where (no^x) is max
*/

/*
In actual approach we will use add every number to a trie
Then we traverse the array & find the max_XOR value for it using the trie , it will take O(32) nearly O(1) time in solving that problem .

we can find it in O(N) * 32 for the whole array
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

    void putBit(int bit, Node *node)
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
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);

            if (!(node->isContains(bit)))
            {
                node->putBit(bit, new Node());
            }

            node = node->next(bit);
        }
    }

    int Max_xor(int num)
    {
        Node *node = root;
        int max_xor = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            int req = 1 - bit;

            if (node->isContains(req))
            {
                // set the ith bit of max_xor
                max_xor = (max_xor | (1 << i));
                node = node->next(req);
                continue;
            }

            node = node->next(bit);
        }

        return max_xor;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        Trie *trie = new Trie();
        int MAX_XOR = 0;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            trie->insert(num);
        }

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int xor_val = trie->Max_xor(num);
            MAX_XOR = max(MAX_XOR, xor_val);
        }

        return MAX_XOR;
    }
};

int main()
{

    return 0;
}