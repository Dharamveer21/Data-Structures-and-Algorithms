#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    // it->first access first element of vector

    vector<int> values;
    for (int &value : values)
    {
        // now actual values comes and we can change in original vector
        // if we use value rather than &values then it make a copy of values
    }

    map<int, string> m;
    m[1] = "abc";

    // time complexity of insertion of key as string is not only log n it also check the string if the string is key

    map<int, string>::iterator it;
    m.insert({1, "abc"});

    // unique keys in map
    // multimap has duplicate keys

    map<int, string>::iterator ip = m.find(1);
    // find function to find required key
    // it return the iterator of that key and if the key is not present in map it returns end()

    m.erase(1);
    // it works on both iterator or key

    m.clear();
    // to clear the map

    // and these functions for all types like string map set vector

    unordered_map<int, int> a;
    // cannot use only things as key whose hash is defined

    // set is same as map with only keys
    set<string> s;
    s.insert("abc");
    unordered_set<int> val;
    multiset<string> val1;

    val1.insert("abc");
    val1.insert("abc");

    auto i1 = val1.find("abc");

    val1.erase(i1); 
    // if we pass iterator than it will only delete iterator otherwise it will delete all values with that iterator

    return 0;
}