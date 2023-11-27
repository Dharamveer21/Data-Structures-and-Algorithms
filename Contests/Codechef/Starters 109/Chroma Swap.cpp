#include <bits/stdc++.h>
using namespace std;

void takeInputs(int n, vector<int> &arr, vector<int> &colorsA, vector<int> &brr, vector<int> &colorsB, map<int, bool> &isColorPresentB);
void fillElementColors(vector<int> &arr, vector<int> &colorsA, vector<int> &brr, vector<int> &colorsB, map<int, multiset<int>> &ElementColors);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n), brr(n);
        vector<int> colorsA(n), colorsB(n);
        map<int, multiset<int>> ElementColors;
        map<int, bool> isColorPresentB;

        takeInputs(n, arr, colorsA, brr, colorsB, isColorPresentB);
        fillElementColors(arr, colorsA, brr, colorsB, ElementColors);

        int prevElement = 1;
        bool isArrayNonDec = true;

        for (int i = 0; i < n; i++)
        {
            int color = colorsA[i];
            int element = arr[i];

            if (!isColorPresentB[color])
            {
                if (element < prevElement)
                {
                    isArrayNonDec = false;
                    cout << "NO" << endl;
                    break;
                }

                prevElement = element;
            }

            else
            {
                auto searchIterator = ElementColors[color].lower_bound(prevElement);

                if (searchIterator == ElementColors[color].end())
                {
                    isArrayNonDec = false;
                    cout << "NO" << endl;
                    break;
                }

                prevElement = *(searchIterator);
                ElementColors[color].erase(searchIterator);
            }
        }

        if (isArrayNonDec)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}

void takeInputs(int n, vector<int> &arr, vector<int> &colorsA, vector<int> &brr, vector<int> &colorsB, map<int, bool> &isColorPresentB)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> colorsA[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> colorsB[i];
        isColorPresentB[colorsB[i]] = true;
    }
}

void fillElementColors(vector<int> &arr, vector<int> &colorsA, vector<int> &brr, vector<int> &colorsB, map<int, multiset<int>> &ElementColors)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int colorA = colorsA[i];
        int colorB = colorsB[i];

        int elementA = arr[i];
        int elementB = brr[i];

        ElementColors[colorA].insert(elementA);
        ElementColors[colorB].insert(elementB);
    }
}