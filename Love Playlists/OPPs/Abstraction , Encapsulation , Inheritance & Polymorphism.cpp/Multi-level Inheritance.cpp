#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

    Animal()
    {
        cout << "Animal" << endl;
    }

    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog Constructor" << endl;
    }
};

class GermanShepherd : public Dog
{
public:
    GermanShepherd()
    {
        cout << "GermanShepherd Constructor" << endl;
    }
};

int main()
{
    GermanShepherd g;
    g.speak();
    cout << g.age << endl;

    return 0;
}