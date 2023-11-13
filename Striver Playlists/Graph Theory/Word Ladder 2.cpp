#include <bits/stdc++.h>
using namespace std;

/*use Bfs in such a manner such that we won't delete the children until all nodes of that level has traversed down the child level This will give TLE*/
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        vector<string> children;
        queue<vector<string>> q;
        unordered_set<string> st;
        int lev = 1;

        for (int i = 0; i < wordList.size(); i++)
        {
            st.insert(wordList[i]);
        }

        q.push({beginWord});

        while (!q.empty())
        {
            vector<string> words = q.front();
            q.pop();

            if (lev != words.size())
            {
                for (int i = 0; i < children.size(); i++)
                {
                    st.erase(children[i]);
                }

                lev++;
                children.clear();
            }

            string word = words[words.size() - 1];

            if (word == endWord)
            {
                ans.push_back(words);
                continue;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original_char = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        words.push_back(word);
                        children.push_back(word);
                        q.push(words);
                        words.pop_back();
                    }
                }

                word[i] = original_char;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}