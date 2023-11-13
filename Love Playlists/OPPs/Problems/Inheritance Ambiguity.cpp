#include <bits/stdc++.h>
using namespace std;

/*
Suppose we have a class A & a class B
we created a class C by hierarchical inheritance from A & B

if class A has a func1 and class B also have the same function name func1
then after inheritance if the object of class C called func1 then which will be called (it shows error) -- this is called inheritance ambiguity

To resolve this issue we use scope resolution operator ' :: '
*/

class A
{
public:
    void func()
    {
        cout << " I am A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << " I am B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;

    // obj.func(); -- it is ambigious
    obj.A::func();
    obj.B::func();

    return 0;
}