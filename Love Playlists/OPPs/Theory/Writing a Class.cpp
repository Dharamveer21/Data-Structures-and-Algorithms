#include <bits/stdc++.h>
using namespace std;

// Defining a class - a user define data type
// Class will not occupy any memory itself
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

int main()
{
    // creating objects of rectangle
    Rectangle r1, r2; // They occupy space in memory
    // only data members will occupy memory , but member functions won't occupy any memory
    // so r1 has length & breadth so it will occupy 4 + 4 = 8 bytes as length & breadth are both integers and integer will take 4 bytes
    
    r1.length = 10; // use dot operators to access members but only the public members , by default the members are private
    r1.breadth = 5;

    r2.length = 5;
    r2.breadth = 15;

    cout << r1.perimeter() << endl;
    cout << r1.area() << endl;

    cout << r2.perimeter() << endl;
    cout << r2.area() << endl;

    return 0;
}

// Memory Organisation of the class

// // // // // // // // // // // // // // // // // // // // // //
//                     /*Heap*/                                //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                     /*Stack*/                               //
//                                                             //
//     r1 - length , r1 - breadth    // 4+4 bytes              //
//     r2 - length , r2 - breadth                              //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                                                             //
//                     /*Code*/                                //
//                                                             //
//      area()                                                 //
//      {...}                                                  //
//                                                             //
//      perimter()                                             //
//      {...}                                                  //
//                                                             //
//      main()                                                 //
//      {...}                                                  //
// // // // // // // // // // // // // // // // // // // // // //
