#include <bits/stdc++.h>
using namespace std;

/*
when we declare a pointer
int value = 5;
int * ptr = &value; --> from here we got to know two things
                        i) The type of data
                        ii) how many bytes to conside in memory

thats why we don't have any pointer data type
like pointer ptr = &value; --> pointer data type doesnot exist
*/

/*
int i = 5;
Now , to create a pointer for i which is an integer value
we use int* ptr = &i;

similarly to create a pointer for ptr which is an integer pointer value
we use int** ptr2 = &ptr; --> it is known as double pointer

and so on ...

in this case a memory block for i is created which has value 5 --> integer

pointer ptr is pointing to i means stores the address of block i --> pointer

pointer ptr2 is pointing to ptr means stores the address of block ptr --> double pointer
*/

void update(int **p, int num)
{
    if (num == 1)
    {
        p = p + 1; // No change
    }

    if (num == 2)
    {
        *p = *p + 1; // change the value of original p , rest of all remains same
    }

    if (num == 3)
    {
        **p = **p + 1; // change the value of original i , rest of all remains same
    }
}

int main()
{
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout << "value of p2 is : " << p2 << endl;    // 0x61feb8
    cout << "address of p2 is : " << &p2 << endl; // 0x61feb4

    cout << "value of p is : " << p << endl;    // 0x61febc
    cout << "value of p is : " << *p2 << endl;  // 0x61febc
    cout << "address of p is : " << &p << endl; // 0x61feb8
    cout << "address of p is : " << p2 << endl; // 0x61feb8

    cout << "value of i is : " << i << endl;     // 5
    cout << "value of i is : " << *p << endl;    // 5
    cout << "value of i is : " << **p2 << endl;  // 5
    cout << "address of i is : " << &i << endl;  // 0x61febc
    cout << "address of i is : " << p << endl;   // 0x61febc
    cout << "address of i is : " << *p2 << endl; // 0x61febc

    // check for double pointer on functions

    i = 5;
    p = &i;
    p2 = &p;

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    update(p2, 1);

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    cout << endl;

    i = 5;
    p = &i;
    p2 = &p;

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    update(p2, 2);

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    cout << endl;

    i = 5;
    p = &i;
    p2 = &p;

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    update(p2, 3);

    cout << "value of i is : " << i << endl;
    cout << "value of p is : " << p << endl;
    cout << "value of p2 is : " << p2 << endl;

    return 0;
}