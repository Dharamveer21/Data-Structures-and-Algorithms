#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- as the sorted order of two anagrams in same so we can create a map betweeen sorted order of a
string & all of its anagrams . We will sort a particular string from strs & store the sorted order vs the string
in the map . Finally we have a group of its anagrams in the strs against a sorted string . Same for each group .

Approach 2 -- here can also use the constraints that only lower case english letters are allowed which are 26
so we can store the given string in a hashArr of size 26 & store the mapping of that string generated from the
given hashArray & its anagrams . Similarly for each string we do the same . Finally store the groups .

N -- number of strings , K -- average size of strings
*/

// Approach 1
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> groupsOfAnagrams;
        unordered_map<string, vector<string>> anagramGroups;

        for (int ind = 0; ind < n; ind++)
        {
            string sortedString = strs[ind];
            sort(sortedString.begin(), sortedString.end());

            string &originalString = strs[ind];
            anagramGroups[sortedString].push_back(originalString);
        }

        for (auto &groups : anagramGroups)
        {
            vector<string> &group = groups.second;
            groupsOfAnagrams.push_back(group);
        }

        return groupsOfAnagrams;
    }
};

// TC : O(N * K * log(K))
// SC : O(N * K)

// Approach 2
class Solution
{
protected:
    string stringFromHashArray(string &str, int *arrCount)
    {
        int n = str.size();
        string sortedString;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = str[ind];
            int val = ch - 'a';

            arrCount[val]++;
        }

        for (int ind = 0; ind < 26; ind++)
        {
            char ch = 'a' + ind;
            int count = arrCount[ind];

            while (count--)
            {
                sortedString.push_back(ch);
            }

            arrCount[ind] = 0;
        }

        return sortedString;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groupsOfAnagrams;
        int n = strs.size(), *arrCount = new int[26]{};
        unordered_map<string, vector<string>> anagramGroups;

        for (int ind = 0; ind < n; ind++)
        {
            string &originalString = strs[ind];
            string sortedString = stringFromHashArray(originalString, arrCount);

            anagramGroups[sortedString].push_back(originalString);
        }

        for (auto &groups : anagramGroups)
        {
            vector<string> &group = groups.second;
            groupsOfAnagrams.push_back(group);
        }

        delete[] arrCount;
        return groupsOfAnagrams;
    }
};

// TC : O(N * (K + 26)) = O(N * K)
// SC : O(N * K + 26) = O(N * K)

int main()
{

    return 0;
}