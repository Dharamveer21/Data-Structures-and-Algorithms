#include <bits/stdc++.h>
using namespace std;

/*sort on basis of size - compare on basis of len */

class Solution
{
public:
    static const bool sorting(string &word1, string &word2)
    {
        return (word1.size() < word2.size());
    }
    
    bool is_preceeder(string &word1, string &word2)
    {
        int ind1 = 0, ind2 = 0, cmp = 2;

        while (ind1 < word1.size() && ind2 < word2.size())
        {
            if (word1[ind1] == word2[ind2])
            {
                ind1++;
                ind2++;
            }
            
            else
            {
                cmp--;
                ind2++;
            }
        }

        if (cmp > 0)
        {
            return true;
        }
           
        return false;
    }

    int longestStrChain(vector<string> &words)
    {
        int ind = 0, max_len = 1;
        pair<int, int> len_indexes[17];
        int longest_chain[words.size()];
        len_indexes[0].first = 0, len_indexes[0].second = -1;

        sort(words.begin(), words.end(), sorting);

        for (int len = 1; len < 17; len++)
        {
            len_indexes[len].first = ind;

            while (ind < words.size() && words[ind].size() == len)
            {
                ind++;
            }

            len_indexes[len].second = ind - 1;
        }
          
        for (int i = 0; i < words.size(); i++)
        {
            int len = words[i].size();
            longest_chain[i] = 1;
            int maxi = 0;

            for (int j = len_indexes[len - 1].first; j <= len_indexes[len - 1].second; j++)
            {
                if (is_preceeder(words[j], words[i]))
                {
                    maxi = max(maxi, longest_chain[j]);
                }
            }
              
            longest_chain[i] += maxi;
            max_len = max(max_len, longest_chain[i]);
        }

        return max_len;
    }
};

int main()
{

    return 0;
}