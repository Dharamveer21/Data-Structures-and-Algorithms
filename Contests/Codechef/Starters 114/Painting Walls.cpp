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
        int length, breadth, budget;
        cin >> length >> breadth >> budget;

        int area = length * breadth;

        int costPerWall = area * 2;
        int wallsCanbePainted = (budget / costPerWall);
        cout << wallsCanbePainted << endl;
    }

    return 0;
}