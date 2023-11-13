#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        // right shift number by i so you got required bit & with 1
        cout << (((num >> i)) & 1);
    }

    cout << endl;
}

int main()
{
    int a = 9;
    int i = 0;

    // to check if ith bit is set or not
    // bitwise and it with a number which has 1 only on ith position
    if (a & (1 << i) != 0)
    {
        cout << "set bit" << endl;
    }

    else
    {
        cout << "unset" << endl;
    }

    // to set i th bit of a number
    // bitwise or it with a number which has 1 only on ith position

    int ans = (a | (1 << i));

    // to unset i th bit of a number
    //  bitwise and with a number which has 0 only and ith position and 1 elsewhere

    ans = (a & (~(1 << i)));

    // togle a bit means if it is 1 make a bit 0 and if it is 1 make it 0
    ans = (a ^ (1 << i));

    // to count no of set bits we use loop with above concept
    // inbuilt function

    cout << __builtin_popcount(a) << endl;//for int
    cout << __builtin_popcountll(1LL << 35) << endl;// for long long

    return 0;
}

/*
   xor gives result - if same then 0 otherwise 1

   m << n --> Left shift operator
   in this the binary of m we add n zero to its right

   m >> n --> right shift operator
   in this the binary of m we delete last n bits

   1 << n =  2 ^ n

   set bits --> 1
   unsetbit --> 0

   we want to check if ith bit is set or not
   we n & 1<<i if it gives 1 then bit is set
*/