#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
public:
    // data members
    int length;
    int breadth;
    
    // member functions
    int area()
    {
        return (length * breadth);
    }

    int perimeter()
    {
        return ((length + breadth) * 2);
    }
};

// Every Pointer takes same amount of memory despite of the data type it is pointing to

int main()
{
    // Create object in stack memory
    Rectangle r;
    Rectangle *p;
    p = &r;

    r.length = 10;
    p->length = 10; // '->' is dereferencing operator which is used to access the members of the class of object
    p->breadth = 15;

    cout << p->area() << endl;
    cout << p->perimeter() << endl;
    
    // Create object in heap memory
    Rectangle *ptr;
    ptr = new Rectangle;

    Rectangle *q = new Rectangle();

    ptr->length = 10;
    ptr->breadth = 10;
    cout << ptr->area() << endl;

    return 0;
}
