#include <bits/stdc++.h>
using namespace std;

/*
all nos of array present in even count
and only 1 element in present in odd times
*/

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 4, b = 6;

    // XOR - same - 0
    //  different - 1

    // x^x = 0
    // x^0 = x

    swap(a, b);

    return 0;
}