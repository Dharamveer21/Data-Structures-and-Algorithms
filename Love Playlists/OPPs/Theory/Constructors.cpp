#include <bits/stdc++.h>
using namespace std;

/*
  Phylosiphically it is not correct to create a object & then assign its properties

  once you created a rectangle there must me some length & breadth values for it , there cannot be garbage values.

  So creating a rectangle & assigning its length & breadth latter is absurd there must be some default size which can be further modified

  So we want the length & breadth to be set at the time of creating the object of the Rectangle class

  Hence we should have a function that will automatically call when we create a object of the class -- these functions are known as Constructors
*/

// Constructor is a function which will have same name as class name & they will not have any written type

/*
There are 4 types of Constructors 3 of which can be written by user otherwise the compiler has a default constructor

1. Default or built in Constructor

2. Non-Parameterized   Constructor  -----]
3. Parameterized       Constructor       ]  user defined
4. Copy                Constructor  -----]
*/

class Rectangle
{
private:
    // data members
    int length;
    int breadth;

public:
    // member functions

    /* All the constructors have same name so it is function overloading */

    // Non Paramterized Constructor
    Rectangle()
    {
        this->length = 0;
        this->breadth = 0;
    }
    
    // Paramterized Constructor
    /* Here we can also provide l = 0 , b = 0 which can behave like Non-Parameterized Constructor also */
    Rectangle(int l, int b)
    {
        this->setLength(l);
        this->setBreadth(b);
    }
    
    // Copy Constructor
    /* Here we have taken it as reference because we don't want that new Rectangle got created when the copy constructor runs */
    Rectangle(Rectangle &rect)
    {
        this->length = rect.length;
        this->breadth = rect.breadth;
    }
    
    void setLength(int l)
    {
        if (l < 0)
        {
            cout << "Length should be positive" << endl;
            return;
        }

        this->length = l;
    }
    
    void setBreadth(int b)
    {
        if (b < 0)
        {
            cout << "Breadth should be positive" << endl;
            return;
        }

        this->breadth = b;
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

/*
Once user created its own constructors then the default constructor disappeared , so we can create a non paramterised constructor for its purpose
*/

int main()
{
    Rectangle r; // At this time the default constructor of the class is called if no constructor is created by user otherwise Non-Parameterized constructor will be called

    cout << "Length : " << r.getLength() << endl;
    cout << "Breadth : " << r.getBreadth() << endl;
    
    cout << "Perimeter : " << r.perimeter() << endl;
    cout << "Area : " << r.area() << endl;

    Rectangle r1; // At this time the Non-Parameterized constructor of the class is called

    cout << "Length : " << r1.getLength() << endl;
    cout << "Breadth : " << r1.getBreadth() << endl;

    cout << "Perimeter : " << r1.perimeter() << endl;
    cout << "Area : " << r1.area() << endl;

    Rectangle r2(10, 5); // At this time the Parameterized constructor of the class was called

    cout << "Length : " << r2.getLength() << endl;
    cout << "Breadth : " << r2.getBreadth() << endl;

    cout << "Perimeter : " << r2.perimeter() << endl;
    cout << "Area : " << r2.area() << endl;

    Rectangle r3(r1); // At this time the copy constructor of the class was called

    cout << "Length : " << r3.getLength() << endl;
    cout << "Breadth : " << r3.getBreadth() << endl;

    cout << "Perimeter : " << r3.perimeter() << endl;
    cout << "Area : " << r3.area() << endl;

    return 0;
}