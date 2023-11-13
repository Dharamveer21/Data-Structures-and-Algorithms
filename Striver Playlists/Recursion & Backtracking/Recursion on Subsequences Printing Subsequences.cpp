#include <bits/stdc++.h>
using namespace std;

// Printing Subsequences
class Solution
{
public:
    int count(string str1, string str2)
    {
        if (str1.size() != str2.size())
        {
            return 0;
        }

        else
        {
            for (int i = 0; i < str1.size(); i++)
            {
                if (str1[i] != str2[i])
                {
                    return 0;
                }
            }
        }

        return 1;
    }

    void subsequences(int ind, string &subsequence, string &s, string &t, int &ans)
    {
        if (ind > s.size())
        {
            for (auto &it : subsequence)
            {
                cout << it << " ";
            }

            cout << endl;

            ans += count(subsequence, t);
            return;
        }

        // we not include ind element
        subsequences(ind + 1, subsequence, s, t, ans);

        // we include ind element
        subsequence.push_back(s[ind]);
        subsequences(ind + 1, subsequence, s, t, ans);
        subsequence.pop_back();
    }

    int numDistinct(string s, string t)
    {
        int ans = 0;
        string subsequence;
        subsequences(0, subsequence, s, t, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
