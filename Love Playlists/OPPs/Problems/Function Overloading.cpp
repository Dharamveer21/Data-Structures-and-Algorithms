#include <bits/stdc++.h>
using namespace std;

// Function Overloading -- When two functions have same name but different set of arguments
/* Function overloading cannot be achieved by only changing the return type of a function or the content of the function
   The arguments must be different
*/

class A
{
public:
    void sayHello()
    {
        cout << "Hello Babbar" << endl;
    }

    void sayHello(string name)
    {
        cout << "Hello Babbar" << endl;
    }

    /* int sayHello() -- cannot be overloading just be changing the return type
    {
        cout << "Hello Babbar" << endl;
        return 1;
    } */
};

int main()
{

    return 0;
}