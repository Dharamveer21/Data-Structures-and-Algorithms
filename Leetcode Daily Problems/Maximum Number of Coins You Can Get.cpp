#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we always got the second highest pile , no matter what way we choose we always get less coins pile than Alice
but we can decrease the coins of bob , we will sort the array in decreasing order .
The last n elements of total (3n) elements are the minimum one that we choose for bob
In the first (2n) elements i want to get the maximum ones but alice will always get more than me
i will choose first two pairs & any one from last n each time so that i got the second maximum value present in the array in sorted manner
*/

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size();
        int AliceMyPart = (2 * (n / 3));
        int maxCoins = 0;
        sort(piles.begin(), piles.end(), greater<int>());

        for (int ind = 1; ind < AliceMyPart; ind += 2)
        {
            int coins = piles[ind];
            maxCoins += coins;
        }

        return maxCoins;
    }
};

// TC : O(n * log(n)) -- sorting time
// SC : O(log(n)) -- size for sorting

int main()
{

    return 0;
}