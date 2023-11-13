#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // they also work for array here we provide address of array
    //  to find min & max element in vector directly
    //  it also returns only min element
    int min = *(min_element(v.begin() + 2, v.end()));
    int max = *(max_element(v.begin() + 2, v.end()));

    // to sum of array we have to provide initial sum
    int sum = accumulate(v.begin(), v.end(), 0);

    // to find occurence of a particular element in vector
    int ct = count(v.begin(), v.end(), 5);

    // to find a elemment in an vector it returns iterator of that element
    auto it = find(v.begin(), v.end(), 2);

    // to reverse the vector or string
    reverse(v.begin(), v.end());

    return 0;
}