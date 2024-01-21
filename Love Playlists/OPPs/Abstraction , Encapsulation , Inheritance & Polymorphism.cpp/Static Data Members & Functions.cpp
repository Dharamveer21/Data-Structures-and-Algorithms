#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    // properties
    int health;
    char level;

public:
    // static data members are the variables that do not belong to a particular object like the time to complete the game in this case , it will be same for all the characters of the game or the objects of the class Hero
    
    // if these members are made public then we can intialize them outside the class using scope resolution operator & also we can directly access it without using any object
    static int time_to_complete;

    // no need for object to call them , also do not have this keyword as they can be called without object
    // static functions can only access the static data members

    static int random()
    {
        cout << time_to_complete << endl;
        return time_to_complete;
    }
    
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

// syntax for static data members -- data type classname :: variablename = value;
int Hero ::time_to_complete = 10;

int main()
{

    Hero ramesh;

    cout << Hero::time_to_complete << endl;
    cout << Hero::random() << endl;

    cout << "Size of Object : " << sizeof(ramesh) << endl;

    ramesh.setHealth(70);
    ramesh.setLevel('A');

    cout << "Health is : " << ramesh.getHealth() << endl;
    cout << "Level is : " << ramesh.getLevel() << endl;

    cout << ramesh.time_to_complete << endl; // it can also be accessed by any object & it value remains same for all objects

    Hero suresh;

    cout << "Size of Object : " << sizeof(suresh) << endl;

    suresh.setHealth(80);
    suresh.setLevel('B');
    suresh.time_to_complete = 20;

    cout << ramesh.time_to_complete << endl; // 20
    cout << suresh.time_to_complete << endl; // 20
    cout << Hero::time_to_complete << endl;  // 20

    cout << "Health is : " << suresh.getHealth() << endl;
    cout << "Level is : " << suresh.getLevel() << endl;

    return 0;
}