#include <bits/stdc++.h>
using namespace std;

/*
Every odd binary number ends with 1
Every even binary number ends with 0
*/

/*
AND , OR & XOR Bitwise Operators

A   B      A & B     A | B   A ^ B    ~A
0   0        0         0       0       1
0   1        0         1       1       1
1   0        0         1       1       0
1   1        1         1       0       0

Left Shift --  5 << 2 , add two zeros in last of binary of 5

Right Shift -- 5 >> 2 , remove last two bits in binary of 5
*/

/*
1 << 0 = 1 = 2^0
1 << 1 = 2 = 2^1
1 << 2 = 4 = 2^2
1 << 3 = 8 = 2^3
1 << 4 = 16 = 2^4

1 << n = 2^n
*/

int main()
{
    // Max value that can be created by 32 bits should be -- 2 ^ 32 - 1
    cout << INT_MAX << endl;
    int a = (1LL << 32) - 1; // -1
    cout << a << endl;

    a = (1LL << 31) - 1; // is equal to INT_MAX
    cout << a << endl;

    unsigned int b = (1LL << 32) - 1; // 4294967295 it shows correctly
    cout << b << endl;

    /*
     This happens because there is a MSB reserved for sign of the number in case of a sign integer
     
     0 is for positive numbers
     1 is for negative numbers
     
     but in case of an unsigned integer there is no such bit thats way it shows the correct value of 2^32 - 1
    */
    return 0;
}