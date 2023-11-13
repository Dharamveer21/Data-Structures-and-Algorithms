#include <bits/stdc++.h>
using namespace std;

// memoisation
int min_energy(int n, vector<int> &heights, vector<int> &energy)
{
    if (energy[n] != -1)
    {
        return energy[n];
    }

    int energy_used_1 = min_energy(n - 1, heights, energy) + abs(heights[n] - heights[n - 1]);
    int energy_used_2 = min_energy(n - 2, heights, energy) + abs(heights[n] - heights[n - 2]);

    return energy[n] = min(energy_used_1, energy_used_2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> energy(n, -1);
    energy[0] = 0;
    energy[1] = abs(heights[1] - heights[0]);
    int ans = min_energy(n - 1, heights, energy);
    return ans;
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    n = n - 1;
    vector<int> energy(n + 1, -1);
    energy[0] = 0;
    energy[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i <= n; i++)
    {
        int energy_used_1 = energy[i - 1] + abs(heights[i] - heights[i - 1]);
        int energy_used_2 = energy[i - 2] + abs(heights[i] - heights[i - 2]);

        energy[i] = min(energy_used_1, energy_used_2);
    }

    int ans = energy[n];
    return ans;
}

// space optimisation
int frogJump(int n, vector<int> &heights)
{
    n = n - 1;
    int prev, sec_prev, curr;
    sec_prev = 0;
    prev = abs(heights[1] - heights[0]);

    for (int i = 2; i <= n; i++)
    {
        int energy_used_1 = prev + abs(heights[i] - heights[i - 1]);
        int energy_used_2 = sec_prev + abs(heights[i] - heights[i - 2]);

        curr = min(energy_used_1, energy_used_2);
        sec_prev = prev;
        prev = curr;
    }

    return curr;
}

int main()
{

    return 0;
}