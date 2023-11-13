#include <bits/stdc++.h>
using namespace std;

/* Multiple operations by one operator */

// Overloading the operator '+'
/*
   As '+' is binary operator its first argument is current obj & other one is input argument
   a + b -- in case of overloading , a -- current obj and b -- input object

   syntax -- return type operator "operator" (arguments)
   {}
*/

class A
{
public:
    int a;
    int b;

    int add()
    {
        return (a + b);
    }

    // overloading '+'
    void operator+(A &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;

        cout << "Output : " << (val2 - val1) << endl;
        cout << "Operator Overloading" << endl;
    }

    // overloading '()'
    void operator()()
    {
        cout << "I am bracket : " << this->a << endl;
    }
};

int main()
{
    A obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    return 0;
}