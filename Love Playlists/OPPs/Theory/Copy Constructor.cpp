#include <bits/stdc++.h>
using namespace std;

/*
There are two Types of Copy Constructors

1. Shallow Copy Constructor
1. Deep    Copy Constructor
*/

// Shallow Copy Constructor
class Test
{
private:
    int a;
    int *p;

public:
    Test(int x)
    {
        this->a = x;
        this->p = new int[a];
    }

    Test(Test &t)
    {
        this->a = t.a;
        this->p = t.p;
    }
};

int main()
{
    Test t1(5);
    Test t2(t1);

    /*
    when the t2 object is created the shallow copy constructor is called & it makes the pointer of t2 as pointing to the same memory location in heap as pointed by p of t1
    So it is actually not a real copy but it points to same memory location as of t1 object
    */

    return 0;
}

// Deep Copy Constructor
class Test
{
private:
    int a;
    int *p;

public:
    Test(int x)
    {
        this->a = x;
        this->p = new int[a];
    }

    Test(Test &t)
    {
        this->a = t.a;
        this->p = new int[a];

        for (int i = 0; i < a; i++)
        {
            this->p[i] = t.p[i];
        }
    }
};

int main()
{
    Test t1(5);
    Test t2(t1);

    /*
    when the t2 object is created the deep copy constructor is called & it makes the pointer of t2 as pointing to the new memory location in heap & also copied the values present in p of t1 to p of t2
    So it is actually makes a real copy , exact same
    */

    return 0;
}