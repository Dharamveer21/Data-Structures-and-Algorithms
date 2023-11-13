#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
     lamda function
    // syntax - > [] square bracket the (int x)(int y) types of variables then {return (x+2);}(2)--pass the agrument

    auto sum = [](int x,int y){ return x + y; };

    cout << sum(2) << endl;
    */

    vector<int> v = {2, 3, 5};

    // all_of is a algorthm
    //none_of
    //anyof

    // it return true if all elements return true
    // it return false if any one element returns false
    cout << all_of(v.begin(), v.end(), [](int x){ return (x > 0); });
    // in the third argument we can pass a function like comparator as lambda function is also a function
    
    //if any one is true then ans is true
    cout << any_of(v.begin(), v.end(), [](int x){ return (x > 0); });

    // if all return false then it will return true
    cout << none_of(v.begin(), v.end(), [](int x){ return (x > 0); });

    return 0;
}