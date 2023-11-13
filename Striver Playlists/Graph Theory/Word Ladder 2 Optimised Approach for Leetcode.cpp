#include <bits/stdc++.h>
using namespace std;

// Optimised Approach for Leetcode
class Solution
{
public:
    void dfs(vector<string> &ans, vector<vector<string>> &result, unordered_map<string, int> &lev)
    {
        string word = ans[ans.size() - 1];
        int level = lev[word];

        if (level == 1)
        {
            vector<string> sol = ans;
            reverse(sol.begin(), sol.end());
            result.push_back(sol);
            return;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char origin = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (lev[word] == level - 1)
                {
                    ans.push_back(word);
                    cout << word << endl;
                    dfs(ans, result, lev);
                    ans.pop_back();
                }
            }

            word[i] = origin;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> result;
        queue<pair<string, int>> q;
        unordered_set<string> st;
        unordered_map<string, int> lev;

        for (int i = 0; i < wordList.size(); i++)
        {
            st.insert(wordList[i]);
        }

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            pair<string, int> word_lev = q.front();
            q.pop();

            string &word = word_lev.first;
            int level = word_lev.second;
            lev[word] = level;

            for (int i = 0; i < word.size(); i++)
            {
                char origin = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }

                word[i] = origin;
            }
        }

        if (lev[endWord] == 0)
        {
            return result;
        }

        vector<string> ans;
        ans.push_back(endWord);
        dfs(ans, result, lev);
        return result;
    }
};

int main()
{

    return 0;
}