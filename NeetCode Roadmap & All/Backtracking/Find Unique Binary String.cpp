#include <bits/stdc++.h>
using namespace std;

// Approach -- Generate all & check simultaneously

// Using Backtracking
class Solution
{
public:
    bool check(string &str, vector<string> &nums)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str == nums[i])
            {
                return false;
            }
        }

        return true;
    }

    void all_permutations(int ind, int n, bool &flag, string &str, vector<string> &nums, string &ans)
    {
        if (ind == n)
        {
            if (check(str, nums))
            {
                ans = str;
                flag = true;
            }

            return;
        }

        if (flag)
        {
            return;
        }

        str.push_back('0');
        all_permutations(ind + 1, n, flag, str, nums, ans);
        str.pop_back();

        str.push_back('1');
        all_permutations(ind + 1, n, flag, str, nums, ans);
        str.pop_back();
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string str, ans;
        bool flag = false;

        all_permutations(0, n, flag, str, nums, ans);
        return ans;
    }
};

// TC : O(2^n * n^2)

// using bitmasking
class Solution
{
public:
    string str_convert(int num, int n)
    {
        string ans;

        for (int i = n; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            char ch = bit + '0';
            ans.push_back(ch);
        }

        return ans;
    }

    bool is_diff(string &str, vector<string> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (str == nums[i])
            {
                return false;
            }
        }

        return true;
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int num = i;
            string str = str_convert(num, n - 1);

            if (is_diff(str, nums))
            {
                return str;
            }
        }

        string ans = str_convert(n, n - 1);
        return ans;
    }
};

// TC : O(n^3)

int main()
{

    return 0;
}