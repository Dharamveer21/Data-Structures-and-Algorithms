#include <bits/stdc++.h>
using namespace std;

// Getters & setters are the functions that are used for input & output private data members

class Hero
{
private:
    // properties
    int health;
    char level;
    double d;
    short int m;

public:
    int getLevel()
    {
        return level;
    }

    int getHealth()
    {
        return health;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    void setHealth(int h)
    {
        health = h;
    }
};

int main()
{
    // creation of object
    Hero ramesh;

    cout << "Size of Object : " << sizeof(ramesh) << endl; // it will output 24 due to class data member greedy alignment & padding

    ramesh.setHealth(70);
    ramesh.setLevel('A');

    cout << "Health is : " << ramesh.getHealth() << endl;
    cout << "Level is : " << ramesh.getLevel() << endl;

    cout << "size of : " << sizeof(ramesh) << endl;

    return 0;
}

/*
it is done by the compiler for fast & quick execution of program , if all variable lie on single cycle it will be very quick for compiler to fetch data , so it uses greedy alignment & padding for that

There are two rules for greedy alignment & padding

1. every variable will start taking bytes in memory from multiple of memory taken by it
e.g. :- int takes 4 bytes so it will only start from 0 , 4, 8 ,12th bytes
e.g. :- char takes 1 byte so it will only start from 0 , 1, 2 ,3rd bytes

2. the total size of the class is always the nearest multiple of the largest data type in its data members
e.g. :- if data members are int (4) , double (8) , char (1) , short int(2) -- then class will takes only multiple of 8 as its size

Memory is assigned to data members in order of there declaration , like if in the above class memory will be assigned like for -- int -- char -- double then short int 

Rule 1 -- for greedy alignment
Rule 2 -- for padding

For the above example the memory alignment & padding is like --

  int    char           double           short int   padding  
0 1 2 3  4 5 6 7  8 9 10 11 12 13 14 15  16 17      18 19 20 21 22 23 -- size of class = 24 as it is the nearest multiple of 8 (which is double) 
*/
