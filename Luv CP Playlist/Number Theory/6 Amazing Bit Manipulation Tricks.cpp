#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << (((num >> i)) & 1);
    }

    cout << endl;
}

int main()
{
    int n = 5, ans;

    // in place of % 2 we can use & 1
    ans = n & 1;

    // in place of / 2 we can use >> 1
    ans = n >> 1;

    // in place of * 2 we can use << 1
    ans = n << 1;

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        cout << ch << endl;
        printBinary((int)ch);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        cout << ch << endl;
        printBinary((int)ch);
    }

    // in case of uppercase letter the next bit to most significant bit is unset , its 5th bit but set for its corresponding lowercase letter rest of all bits are same for both

    // it works for all letters
    // to convert A to a we set its 5th bit
    // A -- 1000001 , a -- 1100001

    char CH = 'A';
    char ch = CH | (1 << 5);
    cout << ch << endl;

    // it works for all letters
    //  to convert a to b we unset its 5th bit

    char CH = 'a';
    char ch = CH & (~(1 << 5));
    cout << ch << endl;

    // simply to convert uppercase to lowercase we can do bitwise or with space

    char CH = 'A';
    char ch = CH | (' ');
    cout << ch << endl; // a

    // to convert lowercase to uppercase we can do bitwise and with underscore
    char CH = 'a';
    char ch = CH & ('_');
    cout << ch << endl; // A

    // make lsb means last i bits of a no unset in single operation
    int a = 59;
    printBinary(59); // 00000111011
    // to unset its bits unset upto 4th bit
    //  we need to & it with a no will 1111111000
    //  and is inversion of ~(0001000 - 1)

    int i = 4; // upto 4th bits
    int b = (a & (~((1 << (i + 1)) - 1)));

    // to clear upto ith bit MSb
    // we need to & it with 000001111111
    int c = (a & ((1 << (i + 1)) - 1));

    // how to check power of 2
    if ((n & (n - 1)) != 0)
    {
        cout << "Not apower of 2" << endl;
    }
    else
    {
        cout << "Yes a power of 2" << endl;
    }
    
    // because power of 2 only contains 100000 and n-1 = 0111111
    // there & will result in 0

    return 0;
}