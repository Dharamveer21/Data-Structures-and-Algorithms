#include <bits/stdc++.h>
using namespace std;

class BaseClass
{
public:
    int var_base;

    void display()
    {
        cout << "Displaying Base class variable var_base : " << var_base << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived;

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

    /* 
    Early Binding --> The pointer of base class will bind to  display function of base class -- it is knows
    as early binding 

    Early binding is also known as static binding or compile time binding
    */

    // We can only access base class memebers through the pointer of base class
    base_class_pointer->var_base = 34;
    base_class_pointer->display();

    DerivedClass *derived_class_pointer;
    derived_class_pointer = &obj_derived;

    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display(); // Here the binding is with display function of derived class 
    
    // The binding of pointers & functions occurs during runtime , thats why it is called runtime polymorphism

    return 0;
}