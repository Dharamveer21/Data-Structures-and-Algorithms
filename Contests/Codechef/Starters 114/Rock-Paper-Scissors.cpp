#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string chefinaMoves;
        cin >> chefinaMoves;

        string chefMoves(n, 'P');

        int movesToWin = (n / 2) + 1;
        int countP = 0, count = 0;

        for (int ind = 0; ind < n; ind++)
        {
            char move = chefinaMoves[ind];

            if (move == 'R')
            {
                chefMoves[ind] = 'P';
                countP++;
            }
        }

        if (movesToWin <= countP)
        {
            cout << chefMoves << endl;
            continue;
        }

        count = countP;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            char move = chefinaMoves[ind];

            if (move == 'P')
            {
                chefMoves[ind] = 'S';
                count++;

                if (count >= movesToWin)
                {
                    break;
                }
            }

            if (move == 'S')
            {
                chefMoves[ind] = 'R';
                count++;

                if (count >= movesToWin)
                {
                    break;
                }
            }
        }

        cout << chefMoves << endl;
    }

    return 0;
}