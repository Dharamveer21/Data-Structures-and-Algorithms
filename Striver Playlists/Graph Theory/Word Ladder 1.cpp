#include <bits/stdc++.h>
using namespace std;

/*Its a graph problem using bfs but not direct graph is formed but we try all children*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st;
        queue<pair<string, int>> q;

        for (int i = 0; i < wordList.size(); i++)
        {
            string word = wordList[i];
            st.insert(word);
        }

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            pair<string, int> word_lev = q.front();
            q.pop();

            string word = word_lev.first;
            int lev = word_lev.second;

            if (word == endWord)
            {
                return lev;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original_letter = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        q.push({word, lev + 1});
                        st.erase(word);
                    }
                }

                word[i] = original_letter;
            }
        }

        return 0;
    }
};

int main()
{

    return 0;
}