#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    int health;
    char level;

public:
    // Default Constructor
    Hero()
    {
        cout << "Constructor Called" << endl;
    }

    // Parameterised Constructor
    Hero(int health, int level)
    {
        this->health = health;
        this->level = level;
    }

    // Copy Constructor
    /* we need to use '&' here because we need to make it call by reference otherwise when we use call by value then it have to create a copy in r which also calls the copy constructor , then it must create copy then the cycle continues , so to prevent it we use call by reference */
    Hero(Hero &r)
    {
        this->health = r.health;
        this->level = r.level;
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

int main()
{
    Hero ramesh;
    Hero *rahul = new Hero;
    Hero rama(5, 'C');
    Hero R(rama);

    // if we have already created the objects & we want to copy one object into other we can use '=' assignment operator

    rama = ramesh;

    return 0;
}