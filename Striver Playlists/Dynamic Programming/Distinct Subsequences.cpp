#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tabulation
    int numDistinct(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        int distinct_sequences[n1][n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                distinct_sequences[ind1][ind2] = 0;

                if (ind1 < ind2)
                {
                    continue;
                }
                
                if (s[ind1] == t[ind2])
                {   
                    int len1 = (ind2 == 0) ? 1 : ((ind1 == 0) ? 0 : distinct_sequences[ind1 - 1][ind2 - 1]);
                    distinct_sequences[ind1][ind2] = len1;
                }

                int len2 = (ind1 == 0) ? 0 : distinct_sequences[ind1 - 1][ind2];
                distinct_sequences[ind1][ind2] += len2;
            }
        }

        return distinct_sequences[n1 - 1][n2 - 1];
    }

    // space optimization
    int numDistinct(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        int curr_distinct_sequences[n2];
        int prev_distinct_sequences[n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                curr_distinct_sequences[ind2] = 0;

                if (ind1 < ind2)
                {
                    continue;
                }

                if (s[ind1] == t[ind2])
                {
                    int len1 = (ind2 == 0) ? 1 : ((ind1 == 0) ? 0 : prev_distinct_sequences[ind2 - 1]);
                    curr_distinct_sequences[ind2] = len1;
                }

                int len2 = (ind1 == 0) ? 0 : prev_distinct_sequences[ind2];
                curr_distinct_sequences[ind2] += len2;
            }

            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                prev_distinct_sequences[ind2] = curr_distinct_sequences[ind2];
            }
        }
        
        return curr_distinct_sequences[n2 - 1];
    }
};

int main()
{

    return 0;
}