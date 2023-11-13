#include <bits/stdc++.h>
using namespace std;
/* Class is always written in this way where we just write the prototype of functions in the class
We write the defination of the class outside it using scope resolution operator*/

// This is a perfect class
class Rectangle
{
private:
    int length;
    int breadth;

public:
    // Constuctors Funtions
    Rectangle();
    Rectangle(int l, int b);
    Rectangle(Rectangle &r);

    // Mutators Funtions
    void setLength(int l);
    void setBreadth(int b);

    // Accessors Funtions
    int getLength();
    int getBreadth();

    // Facilitators Funtions
    int perimeter();
    int area();

    // Enquiry or Inspective Funtions
    bool isSquare();

    // Destructor Funtions
    ~Rectangle();
};

int main()
{
    Rectangle r1(10, 10);
    cout << "Area : " << r1.area() << endl;

    if (r1.isSquare())
    {
        cout << "A Square" << endl;
    }

    else
    {
        cout << "Not a Square" << endl;
    }

    return 0;
}

Rectangle ::Rectangle()
{
    this->length = 1;
    this->breadth = 1;
}

Rectangle ::Rectangle(int l, int b)
{
    this->length = l;
    this->breadth = b;
}

Rectangle ::Rectangle(Rectangle &r)
{
    this->length = r.length;
    this->breadth = r.breadth;
}

void Rectangle ::setLength(int l)
{
    this->length = l;
}

void Rectangle ::setBreadth(int b)
{
    this->breadth = b;
}

int Rectangle ::getLength()
{
    return (this->length);
}

int Rectangle ::getBreadth()
{
    return (this->breadth);
}

int Rectangle ::perimeter()
{
    return (2 * ((this->length) + (this->breadth)));
}

int Rectangle ::area()
{
    return ((this->length) * (this->breadth));
}

bool Rectangle ::isSquare()
{
    return ((this->length) == (this->breadth));
}

Rectangle ::~Rectangle()
{
    cout << "Rectangle Destroyed" << endl;
}
