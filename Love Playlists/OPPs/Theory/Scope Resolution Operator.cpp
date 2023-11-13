#include <bits/stdc++.h>
using namespace std;

/* There arw two methods of writing member functions inside a class

Method 1 -- when we elaborate the function inside the class
example:- area();

Method 2 -- when we elaborate the function outside the class
example:- perimeter();
*/

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        this->length = l;
        this->breadth = b;
    }

    int area()
    {
        return (length * breadth);
    }

    int perimeter();
};

int main()
{
    Rectangle r(10, 5);
    cout << r.area() << endl;
    cout << r.perimeter() << endl;
    return 0;
}

// Scope Resolution operator shows that the scope of this function is still only inside the class

// ReturnType ClassName ScopeResolution FunctionName
int Rectangle::perimeter()
{
    return ((length + breadth) * 2);
}

/*
 The main difference arises in compilation & running of the code
 
 in case of area() function :- 
 If we write the defination of function inside the class it will be the inline functions & the machine code for inline function is replaced with the calling statement of that function inside the machine code of main function
 the machine code for inline functions is not generated seprately 

 but in case of perimeter function :-
 if we write the defination of function outiside the class using scope resolution operator its machine code is generated seprately from main code & when it is called it goes to that seprate code & calulates the result & output it in main function

  Now inline functions must be simple ,so when the defination of the function is complex we must define it outside the class

  also the defination of function is seprate piece of code so it must be written seprately
*/