#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> mask(n, 0);

    for (int i = 0; i < n; i++)
    {
        int num_workers;
        cin >> num_workers;

        for (int j = 0; j < num_workers; j++)
        {
            int day;
            cin >> day;

            mask[i] = (mask[i] | (1 << day));
        }
    }

    int person1 = -1, person2 = -1;
    int mx_days = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = (mask[i] & mask[j]);
            int common_days = __builtin_popcount(intersection);

            if (mx_days < common_days)
            {
                mx_days = common_days;
                person1 = i;
                person2 = j;
            }

            cout << i << " " << j << " " << common_days << endl;
        }
    }

    cout << "mx_days : " << mx_days << endl;
    cout << "person1 : " << person1 << endl;
    cout << "person2 : " << person2 << endl;
    
    return 0;
}