#include <bits/stdc++.h>
using namespace std;

/*
2 Approches - 1st use lcs & min of max - it fails because lcs may not be part of change string like teacher --> botcher
2nd use - simple recursion with try all three ways - its the correct one
*/

class Solution
{
public:
    // memoisation
    int mini_distance(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &min_dist)
    {
        // base cases
        if (ind1 == -1 || ind2 == -1)
        {
            return (max(ind1 + 1, ind2 + 1));
        }

        if (min_dist[ind1][ind2] != -1)
        {
            return min_dist[ind1][ind2];
        }

        if (s1[ind1] == s2[ind2])
        {
            return min_dist[ind1][ind2] = mini_distance(ind1 - 1, ind2 - 1, s1, s2, min_dist);
        }

        // replace
        int len_replace = mini_distance(ind1 - 1, ind2 - 1, s1, s2, min_dist) + 1;

        // delete
        int len_delete = mini_distance(ind1 - 1, ind2, s1, s2, min_dist) + 1;

        // insert
        int len_insert = mini_distance(ind1, ind2 - 1, s1, s2, min_dist) + 1;

        return min_dist[ind1][ind2] = (min(len_replace, min(len_delete, len_insert)));
    }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> min_dist(n1, vector<int>(n2, -1));
        return mini_distance(n1 - 1, n2 - 1, word1, word2, min_dist);
    }

    // tabulation
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();

        if (n1 == 0 || n2 == 0)
        {
            return max(n1, n2);
        }

        int min_dist[n1][n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (word1[ind1] == word2[ind2])
                {
                    min_dist[ind1][ind2] = (ind1 == 0 || ind2 == 0) ? (max(ind1, ind2)) : min_dist[ind1 - 1][ind2 - 1];
                    continue;
                }

                // replace
                int len_replace = (ind1 == 0 || ind2 == 0) ? (max(ind1, ind2)) : min_dist[ind1 - 1][ind2 - 1];

                // delete
                int len_delete = (ind1 == 0) ? (ind2) : min_dist[ind1 - 1][ind2];

                // insert
                int len_insert = (ind2 == 0) ? (ind1) : min_dist[ind1][ind2 - 1];

                min_dist[ind1][ind2] = min(len_replace, min(len_delete, len_insert)) + 1;
            }
        }

        return min_dist[n1 - 1][n2 - 1];
    }

    // space optimization
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();

        if (n1 == 0 || n2 == 0)
        {
            return max(n1, n2);
        }

        int curr_min_dist[n2];
        int prev_min_dist[n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (word1[ind1] == word2[ind2])
                {
                    curr_min_dist[ind2] = (ind1 == 0 || ind2 == 0) ? (max(ind1, ind2)) : prev_min_dist[ind2 - 1];
                    continue;
                }

                // replace
                int len_replace = (ind1 == 0 || ind2 == 0) ? (max(ind1, ind2)) : prev_min_dist[ind2 - 1];

                // delete
                int len_delete = (ind1 == 0) ? (ind2) : prev_min_dist[ind2];

                // insert
                int len_insert = (ind2 == 0) ? (ind1) : curr_min_dist[ind2 - 1];

                curr_min_dist[ind2] = min(len_replace, min(len_delete, len_insert)) + 1;
            }

            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                prev_min_dist[ind2] = curr_min_dist[ind2];
            }
        }

        return curr_min_dist[n2 - 1];
    }
};

int main()
{

    return 0;
}
