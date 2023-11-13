#include <bits/stdc++.h>
using namespace std;

int main()
{
    // array vectors must be sorted
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 5);

    // lower_bound & upper_bound returns iterator
    // lower bound returns first occurence of given value or if not present then just greater than it

    it = upper_bound(v.begin(), v.end(), 5);
    // upperbound returns first greater element of given value

    set<int> s;
    map<int, int> m;

    // in case of set and map
    auto it1 = s.lower_bound(5);
    auto it2 = m.upper_bound(6);// in case of map these functions can only apply on keys

    return 0;
}