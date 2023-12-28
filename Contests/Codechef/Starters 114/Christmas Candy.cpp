#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--)
    {
        int numPeople;
        cin >> numPeople;

        vector<int> value(numPeople, 0);

        for (int &val : value)
        {
            cin >> val;
        }

        int maxValue = 0, giftCount = 0;

        for (int ind = 0; ind < numPeople; ind++)
        {
            int currValue = value[ind];

            if (maxValue > currValue)
            {
                giftCount++;
            }

            maxValue = max(maxValue, currValue);
        }

        cout << giftCount << endl;
    }

    return 0;
}