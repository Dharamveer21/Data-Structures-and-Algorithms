#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    // properties
    int health;
    char level;

public:
    Hero(int health, int level)
    {
        this->health = health;
        this->level = level;
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
    // static allocation
    Hero ramesh(10, 11);

    cout << "Size of Object : " << sizeof(ramesh) << endl;

    ramesh.setHealth(70);
    ramesh.setLevel('A');

    cout << "Health is : " << ramesh.getHealth() << endl;
    cout << "Level is : " << ramesh.getLevel() << endl;

    // Dynamic Allocation
    Hero *b = new Hero(10, 11);

    cout << "Size of Object : " << sizeof(*b) << endl;

    b->setHealth(80);
    b->setLevel('B');

    cout << "Health is : " << b->getHealth() << endl;
    cout << "Level is : " << b->getLevel() << endl;

    return 0;
}