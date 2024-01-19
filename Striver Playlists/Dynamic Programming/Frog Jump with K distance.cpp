#include <bits/stdc++.h>
using namespace std;

// memoisation
int min_energy(int ind, int k, vector<int> &heights, vector<int> &energy)
{
    if (energy[ind] != -1)
    {
        return energy[ind];
    } 

    int energy_used = INT_MAX;

    for (int i = max(0, ind - k); i < ind; i++)
    {
        energy_used = min(energy_used, (min_energy(i, k, heights, energy) + abs(heights[ind] - heights[i])));
    }

    return energy[ind] = energy_used;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> energy(n, -1);
    int k = 2;
    energy[0] = 0;
    energy[1] = abs(heights[1] - heights[0]);
    int ans = min_energy(n - 1, k, heights, energy);
    return ans;
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    int k = 2;
    n = n - 1;
    vector<int> energy(n + 1, -1);
    energy[0] = 0;
    energy[1] = abs(heights[1] - heights[0]);

    for (int ind = 2; ind <= n; ind++)
    {
        int energy_used = INT_MAX;

        for (int i = max(0, ind - k); i < ind; i++)
        {
            energy_used = min(energy_used, (energy[i] + abs(heights[ind] - heights[i])));
        }

        energy[ind] = energy_used;
    }

    int ans = energy[n];
    return ans;
}

// space optimisation

/*
it only optimise the space from O(N) to  O(K) and in worst case it will follow O(N)
*/

int main()
{

    return 0;
}