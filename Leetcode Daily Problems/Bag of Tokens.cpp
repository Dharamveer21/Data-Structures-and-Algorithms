#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a 2-pointer solution , first of all we sort the tokens array . Now we will start from minimum
token value & subtract the token values until it reduces to zero . Whenever it becomes zero or tends to less
than zero , we add tokens from maximum & reduce the score . until the left & right pointer meets each other .
*/

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int start = 0, end = tokens.size() - 1;
        int score = 0, maxScore = 0;

        sort(tokens.begin(), tokens.end());

        while (start <= end)
        {
            if (power >= tokens[start])
            {
                power = power - tokens[start++];
                score = score + 1;

                maxScore = max(score, maxScore);
            }

            else if (score > 0)
            {
                power = power + tokens[end--];
                score = score - 1;
            }

            else
            {
                break;
            }
        }

        return maxScore;
    }
};

// TC : O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}