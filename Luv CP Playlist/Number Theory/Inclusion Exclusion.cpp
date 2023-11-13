#include <bits/stdc++.h>
using namespace std;

bool isvowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

vector<string> all_subsets(string &s)
{
    vector<string> subsets;
    int sz = (1 << s.size());

    for (int mask = 0; mask < sz; mask++)
    {
        string subset;

        for (int i = 0; i < s.size(); i++)
        {
            if (mask & (1 << i))
            {
                subset.push_back(s[i]);
            }
        }

        if (subset.size())
        {
            subsets.push_back(subset);
        }
    }

    return subsets;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        unordered_map<string, int> hsh;

        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vowel;

            for (char &ch : s[i])
            {
                if (isvowel(ch))
                {
                    distinct_vowel.insert(ch);
                }
            }

            string str;

            for (auto &ch : distinct_vowel)
            {
                str.push_back(ch);
            }

            vector<string> all_combinations = all_subsets(str);

            for (string &st : all_combinations)
            {
                hsh[st]++;
            }
        }

        long long ans = 0;

        for (auto &pr : hsh)
        {
            if (pr.second < 3)
            {
                continue;
            }

            long long ct = pr.second;
            long long ways = (((ct) * (ct - 1) * (ct - 2)) / 6);

            if (pr.first.size() & 1)
            {
                ans += ways;
            }

            else
            {
                ans -= ways;
            }
        }

        cout << ans << endl;
    }

    return 0;
}