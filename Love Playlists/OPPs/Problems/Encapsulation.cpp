#include <bits/stdc++.h>
using namespace std;

// Rapping up data members & members functions together in a single entity(class) is encapsulation

// Fully Encapsulated class - when all data members are private , so that they can be accessed inside the class only
// Encapsulation is Information or Data Hiding ,
// Advantages -- if we want we can make some of data members as read only , code reusability

class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

int main()
{
    Student st;
    cout << st.getAge() << endl;
    return 0;
}