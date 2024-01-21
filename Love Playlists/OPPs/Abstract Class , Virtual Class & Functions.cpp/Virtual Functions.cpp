#include <bits/stdc++.h>
using namespace std;

class BaseClass
{
public:
    int var_base = 1;

    /*
    when we made this function virtual the base class pointer is pointing to derived class object will bind
    to the display function of derived class -- It is called as late binding

    Late Binding is also known as dynamic binding or run time binding
    */
    virtual void display()
    {
        cout << "Displaying Base class variable var_base : " << var_base << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived = 2;

    void display()
    {
        cout << "Displaying Base class variable var_base : " << var_base << endl;

        cout << "Displaying Base class variable var_derived : " << var_derived << endl;
    }
};

int main()
{
    BaseClass *base_class_pointer;
    BaseClass obj_base;

    DerivedClass obj_derived;
    base_class_pointer = &obj_derived;

    base_class_pointer->display();
    return 0;
}