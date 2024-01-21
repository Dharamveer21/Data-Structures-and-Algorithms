#include <bits/stdc++.h>
using namespace std;

class Test
{
    int a;
    int b;

public:
    /*
     Test(int i, int j) : a(i), b(j) -- correct value
     Test(int i, int j) : a(i), b(i+j) -- correct value
     Test(int i, int j) : a(i), b(a+j) -- correct value
     Test(int i, int j) : b(j), a(i + b) --> garbage value , because a will initialise first , so as a = i + b
     until this time b is not initialsed so it will have garbage value so a garbage value will be assigned to a
     Test(int i, int j) : b(a + j), a(i) --> correct value , because a will initialise first & it will have
     correct value , then b will get correct value as b = a + j
    */

    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor execited" << endl;
        cout << "Value of a is : " << a << endl;
        cout << "Value of b is : " << b << endl;
    }
};

int main()
{
    Test t(4, 6);
    return 0;
}