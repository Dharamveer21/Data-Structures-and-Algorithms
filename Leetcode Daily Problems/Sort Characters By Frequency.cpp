#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- we can use a vector of pair<char,int> of size 123 to store the count of each character in the
array . Now we can sort it in decreasing order using the comparator sort & finally create the result array .

Approach 2 -- we can use a heap , we can store the pair of pair of char & its count of each character in maxHeap
& then fetch the values in decreasing order & put it in the string . In case of heap approach we need to use the
count arr of size 123 for the array it is consuming more space . So first approach is better one .
*/

class Solution
{
protected:
    bool static const cmp(pair<char, int> &p1, pair<char, int> &p2)
    {
        return (p1.second > p2.second);
    }

public:
    // Approach 1
    string frequencySort(string s)
    {
        string frequencySortedString;
        vector<pair<char, int>> charCount(123, {' ', 0});

        for (char &ch : s)
        {
            int index = ch;
            charCount[index].first = ch;
            charCount[index].second += 1;
        }

        sort(charCount.begin(), charCount.end(), cmp);

        for (int ind = 0; ind < 123; ind++)
        {
            pair<char, int> node = charCount[ind];

            char alphabet = node.first;
            int frequency = node.second;

            while (frequency--)
            {
                frequencySortedString.push_back(alphabet);
            }
        }

        return frequencySortedString;
    }

    // Approach 2
    string frequencySort(string s)
    {
        string frequencySortedString;
        int *charCount = new int[123]{};
        priority_queue<pair<int, char>> maxHeap;

        for (char &ch : s)
        {
            int index = ch;
            charCount[index] += 1;
        }

        for (int ind = 0; ind < 123; ind++)
        {
            char alphabet = ind;
            int frequency = charCount[ind];

            if (frequency != 0)
            {
                maxHeap.push({frequency, alphabet});
            }
        }

        while (!maxHeap.empty())
        {
            pair<int, char> node = maxHeap.top();
            maxHeap.pop();

            int frequency = node.first;
            char alphabet = node.second;

            while (frequency--)
            {
                frequencySortedString.push_back(alphabet);
            }
        }

        delete[] charCount;
        return frequencySortedString;
    }
};

// TC : O(N * log(N))
// SC : O(N)

int main()
{
    return 0;
}