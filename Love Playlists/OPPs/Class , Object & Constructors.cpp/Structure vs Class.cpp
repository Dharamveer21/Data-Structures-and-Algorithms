#include <bits/stdc++.h>
using namespace std;

/*
In structure of C language we have only data members but in C++ we have both data members & member functions
In c++ structure is same as the class

the only difference is by default all the members of structure are public & by default all the members of class are private
unless we provide the mode in class & structure from our side
*/

struct Demo1
{
private:
    int x = 10;
    int y = 5;

public:
    void Display()
    {
        cout << x << " " << y << endl;
    }
};

class Demo2
{
private:
    int x = 10;
    int y = 5;

public:
    void Display()
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    Demo1 st;
    Demo2 obj;

    st.Display();
    obj.Display();
    return 0;
}