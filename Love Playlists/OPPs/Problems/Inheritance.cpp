#include <bits/stdc++.h>
using namespace std;

/*
suppose we have a class as "Human" which have certian characterstics of Humans
then we create two more classes male & female , these class will contain all the charactertics of human class along with their specific characterstics

so here we can say male class is inherited from the Human class , this is inheritance

Human class -  will be called as Parent Class or Super Class
Male class  -  will be called as Child Class or Sub Class
*/

/*
Access Modifiers : Private , public , protected

Protected : can only be used by member functions of a class like private but derived class can access these members

In case of super class it is the mode of the data member or the member function present in the parent class or super class

In Case of subclass it is the mode of inheritance which will tell wheather any data member or member function of the parent class is inheritable or not

Mode of Members of Super Class             Mode of Inheritance          Mode of those members in Sub Class    

Public                                      Public                          Public
Public                                      Protected                       Protected 
Public                                      Private                         Private

Protected                                   Public                          Protected 
Protected                                   Protected                       Protected
Protected                                   Private                         Private 
 
Private                                     Public                          NA (Not accessible)
Private                                     Protected                       NA
Private                                     Private                         NA  
*/

class Human
{
public:
    int height;
    int weight;
    int age;

private:
    int getweight()
    {
        return weight;
    }

public:
    void setWeight(int w)
    {
        this->weight = w;
    }
};

// syntax - class "child class" : "mode" "parent class"
class Male : public Human
{
public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }
};

int main()
{
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;

    cout << object1.color << endl;
    object1.setWeight(100);
    cout << object1.weight << endl;
    object1.sleep();
 
    return 0;
}
