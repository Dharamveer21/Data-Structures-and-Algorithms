#include <bits/stdc++.h>
using namespace std;

/*
 int num = 5;

 This statement will create a block of memory of a particular address & put 5 in it

 let the address be 120

 In the Symbol table : name of variables are mapped with the address of the memory of that block
 num - 120

*/

int main()
{
    int num = 5;
    cout << num << endl;

    // address operator -- &
    cout << "address of num is : " << &num << endl; // in hexadecimal format

    /*
    pointer -- store address
    it will create a pointer variable which contains the address of other variable

    int i = 10;
    int *ptr = &i;

    char ch = 'm;
    char *ptr = &ch;

    double db = 10.0209382938;
    double *ptr = &db;

    Pointer must of the same datatype as the datatype stored at that address

   * -- value at operator or dereference operator
   & -- address of operator or reference operator

   i++ == (*ptr)++ --> true
*/

    int *ptr = &num;
    cout << "address is : " << ptr << endl;
    cout << "value is : " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;
    cout << "address is : " << p2 << endl;
    cout << "value is : " << *p2 << endl;

    // Pointers store address of starting bit only -- thats why the size of pointer is same for different data types
    cout << "size of integer_pointer is : " << sizeof(ptr) << endl;
    cout << "size of double_pointer is : " << sizeof(p2) << endl;

    // pointer to int is created and pointing to some garbage address
    // it is a bad practice
    int *ptr1;

    int i = 5;

    // both ways of inisialisng the pointers is allowed

    int *p = 0;
    p = &i;

    int *q = &i;

    int a = num;
    a++; // this will not change the value at num

    int *ptr2 = &num;
    (*ptr2)++; // this will change the value of num

    // coping a pointer
    // They will be exactly same
    int *ptr3 = ptr2; // ptr2 is address of the num & it assign it to the ptr3 which is a new pointer
    cout << ptr2 << " - " << ptr3 << endl;
    cout << *ptr2 << " - " << *ptr3 << endl;

    // Pointer Aithematic -- Addition
    /*
       *t = * t + 1;
       value at adress stored in t = value at address stored in t + 1

       but if we add a num in pointer then it is equal to
       t = t + 1
       new address = old adress + 1 * (sizeof(num))

       it jumps to next variable of same type or next location

       incase of integer it jumps 4 bytes
       incase of char it jumps 1 bytes
       incase of double it jumps 8 bytes
    */

    int ind = 3;
    int *t = &ind;

    cout << "before t : " << t << endl;
    t = t + 1;
    cout << "after t : " << t << endl;

    return 0;
}