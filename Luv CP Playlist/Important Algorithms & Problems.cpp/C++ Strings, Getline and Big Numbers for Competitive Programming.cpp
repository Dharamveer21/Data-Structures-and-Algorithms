#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*string str1 = "Hello", str2 = "World";
    cout << str1 << endl;
    cin >> str1;
    cout << str1;

    // cin takes upto space and next line

    // concatenation
    string result = str1 + " " + str2;
    cout << result << endl;

*/
    // getline function for input the complete string
    int t;
    cin >> t;
    cin.ignore();// to shift cursor to next line , so that getline doesn't take space as input after t
    while (t--)
    {
        string str1, str2;
        getline(cin, str1); // take whole line
        getline(cin, str2);
    }

// big numbers in strings > 10^18

    return 0;
}