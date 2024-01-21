#include <bits/stdc++.h>
using namespace std;

/*
When we make an object of derived class , it automatically calls the constructor of its base class ,
firstly the constructor of base class is called then of dervied class

When we have more arguments in constructor of derived class , some of which are for calling constructor of
base class . So we use call the constructor of base class inside the derived class manually

The constructor of virtual base class is invoked first before the non vitual base classes

If there are multiple virtual base classes then they will be called in order
*/

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }

    void printDataBase1(void)
    {
        cout << "The value of data1 is : " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }

    void printDataBase2(void)
    {
        cout << "The value of data2 is : " << data2 << endl;
    }
};

// order matter here , constructors are called according to order here
class Derived : public Base1, public Base2
{
    int derived1, derived2;

public:
    // Order doesn't matter here
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;

        cout << "Derived Class Constuctor called" << endl;
    }

    void printDataDerived(void)
    {
        cout << "The value of derived1 is : " << derived1 << endl;
        cout << "The value of derived2 is : " << derived2 << endl;
    }
};

int main()
{
    Derived harry(1, 2, 3, 4);
    harry.printDataBase1();

    return 0;
}