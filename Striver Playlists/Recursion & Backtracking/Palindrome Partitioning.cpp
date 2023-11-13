#include <bits/stdc++.h>
using namespace std;

int main()
{
      
    return 0;
}

class Solution
{
public:
    bool isPalindrome(string &str)
    {
        int start = 0;
        int end = str.size() - 1;

        while (start <= end)
        {
            if (str[start++] != str[end--])
            {
                return false;
            }
        }

        return true;
    }

    void palindrome_partition(int ind, string &s, vector<string> &poss_partition, vector<vector<string>> &all_solutions)
    {
        if (ind == s.size())
        {
            all_solutions.push_back(poss_partition);
            return;
        }

        for (int sz = 1; sz <= s.size(); sz++)
        {
            if (ind + sz > s.size())
            {
                break;
            }

            string str = s.substr(ind, sz);

            if (isPalindrome(str))
            {
                poss_partition.push_back(str);
                palindrome_partition(ind + sz, s, poss_partition, all_solutions);
                poss_partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> poss_partition;
        vector<vector<string>> all_solutions;
        palindrome_partition(0, s, poss_partition, all_solutions);
        return all_solutions;
    }
};