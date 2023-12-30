#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Dog d;
    d.speak();
    /*Here we have changed the implimentation of speak function in child class , thats why it only calls the function implimentation of child class
      
    If there were no function like speak in Dog class it will called the function speak of Animal class -- it will show speaking instead of barking
    */

    return 0;
}