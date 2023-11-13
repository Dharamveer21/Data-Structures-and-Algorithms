#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    // properties
    int health;
    char level;

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
    // static allocation
    Hero ramesh;

    cout << "Size of Object : " << sizeof(ramesh) << endl;

    ramesh.setHealth(70);
    ramesh.setLevel('A');

    cout << "Health is : " << ramesh.getHealth() << endl;
    cout << "Level is : " << ramesh.getLevel() << endl;

    // Dynamic Allocation
    Hero *b = new Hero;

    cout << "Size of Object : " << sizeof(*b) << endl;

    b->setHealth(80);
    b->setLevel('B');

    cout << "Health is : " << b->getHealth() << endl;
    cout << "Level is : " << b->getLevel() << endl;

    return 0;
}