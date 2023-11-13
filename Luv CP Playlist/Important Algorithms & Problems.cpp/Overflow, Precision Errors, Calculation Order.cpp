#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 1e8;
    int b = 1e8;
    char m = 'c';
    cout << (m + 1) << endl; // calucation in int data type = 'c' + 1 = 99 +1
    // calculation is always done in higher data type
    long long c = a * 1LL * b;  // due to 1LL all the calculation will be in long long
    cout << fixed << c << endl; // fixed key_word to print ans in normal from scientic notations
    return 0;
}

// data type order of calculation
/*
double - highest
float
long long
long
int
char - lowest
*/

// Double & Float has precision error in case of large integers , thats why we should use only int data type