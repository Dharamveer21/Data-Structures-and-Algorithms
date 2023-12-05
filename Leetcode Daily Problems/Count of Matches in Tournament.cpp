#include <bits/stdc++.h>
using namespace std;

/*
Approach -- 1st is like looping until n becomes 1 & count the number of matches
Approach -- 2nd is that for the elemination of each team 1 match must pe played , means if there are n teams & finally 1 team will be
winner this means (n-1) teams will be eleminated & 1 team eleminates in 1 match , means a total to (n-1) matches must pe played
*/

class Solution
{
public:
    int numberOfMatches(int n)
    {
        return (n - 1);
    }
};

// TC : O(1)
// SC : O(1)

int main()
{

    return 0;
}