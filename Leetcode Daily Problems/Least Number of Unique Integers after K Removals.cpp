#include <bits/stdc++.h>
using namespace std;

/*
Approach -- The simple logic is that we have to delete the least frequent elements first to have least unique
left after the operation . For this we need frequency of elements in an array .

This problem can be solved using multiple ways --
1. Sort the freq array & started deleting elements from start until we delete K elements return remaining
length of array which is still not deleted .

2. We can put the frequencies in a minHeap & started deleting them until K elements are deleted final remaining
size of the heap is the number of least unique elements .

3. The above two approaches takes O(n * log(n)) time but third one is O(n) time algorithm . In this method we
will use the constraint that the maximum frequency of any element is equal to len of the array . So we can use a
hash method to store the occurrence of the frequency of the elements as index & the number of times the same
frequency occurred as its value . Now this array is sorted in a way that the least frequency is at the lowest
index & we just have to traverse array while deleting the frequencies * their occurrence until K
return final count of frequencies whose occurrence is non zero . I am implementing the approach 3 only
*/

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        int n = arr.size(), toRemove = k;
        int leastNumOfUniqueElements = 0;
        unordered_map<int, int> frequencies;
        vector<int> freqCount(n + 1, 0);

        for (int ind = 0; ind < n; ind++)
        {
            int num = arr[ind];
            frequencies[num] += 1;
        }

        for (auto &fq : frequencies)
        {
            int freq = fq.second;
            freqCount[freq]++;
        }

        for (int freq = 0; freq <= n; freq++)
        {
            int count = freqCount[freq];

            if (toRemove != 0)
            {
                int canRemove = count * freq;

                if (canRemove <= toRemove)
                {
                    toRemove -= canRemove;
                    continue;
                }

                count -= toRemove / freq;
                toRemove = 0;
            }

            leastNumOfUniqueElements += count;
        }

        return leastNumOfUniqueElements;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}