#include <bits/stdc++.h>
using namespace std;

/*
We have to hide the data members avoid the mishandling of data
for example in the below class if anyone gives the value of the data absurd like length = -5 (which cannot be negative but if user gives it) and breadth = 10

then the value of :- area is (-5)*(10) = -50 , but area cannot be negative
so the user may say that the class is wrong but actually the class is correct but the user has given a wrong input value
so from such type of mishandling of data we need to make data members private & create functions for taking appropriate input for each data member

and when we write classess we make perfect code , thats why we use private mode for data members
in Public mode we write some member functions for read & write operations for data members
*/

class Rectangle
{
private:
    // data members
    int length;
    int breadth;

public:
    // member functions
    void setLength(int length)
    {
        if (length < 0)
        {
            cout << "Length should be positive" << endl;
            return;
        }

        this->length = length; // this keyword is used to pointed the current object of the class which is calling the functions , it is mainly used when the formal paramters of any member function is named same as the data members of that class
    }

    void setBreadth(int breadth)
    {
        if (breadth < 0)
        {
            cout << "Breadth should be positive" << endl;
            return;
        }

        this->breadth = breadth;
    }

    int getLength()
    {
        return (this->length);
    }
    
    int getBreadth()
    {
        return (this->breadth);
    }

    int area()
    {
        return (length * breadth);
    }

    int perimeter()
    {
        return ((length + breadth) * 2);
    }
};

int main()
{
    Rectangle r;

    r.setLength(10);
    r.setBreadth(5);
    
    cout << "Length is : " << r.getLength() << endl;
    cout << "Breadth is : " << r.getBreadth() << endl;
    cout << "Area is : " << r.area() << endl;
    cout << "Perimeter is : " << r.perimeter() << endl;

    return 0;
}

/*
These are property function

Mutators -- set functions for data members , write property
Accessors -- get functions for data members , read property
*/