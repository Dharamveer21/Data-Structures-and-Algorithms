#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// we can also write class in other file & include it using #include "Hero.cpp"
// in case of empty class , 1 byte is allocated to its object for keeping its track or identification

/*
Access Modifiers --
1. Private : only accessible inside the class
2. Public : accessible both inside & outside the class
3. Protected : accessible to any friend or member function of a derived class
*/

class Hero
{
public:
    // properties
    int health;
    char level;

    void print()
    {
        cout << level << endl;
    }

    ~Hero()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    // creation of object
    Hero ramesh;

    ramesh.health = 70;
    ramesh.level = 'A';

    cout << "Health is : " << ramesh.health << endl;
    cout << "Level is : " << ramesh.level << endl;

    cout << "size of : " << sizeof(ramesh) << endl;

    Hero *obj = new Hero;
    delete obj; // at this time also the destructor called

    /*
    for statistically created obj the destructor is called by itself
    but for dynamically created obj we need to call the destructor
    */

    return 0;
}

int main()
{

    return 0;
}