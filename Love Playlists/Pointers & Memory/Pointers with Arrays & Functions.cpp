#include <bits/stdc++.h>
using namespace std;

// Pointers with Arrays
/* 
int arr[10];
it means a 40 bytes memory is generated & arr is the address of the first element of the array
*/

int main()
{
    // 2 is Oth element , -6 is 1st , 6 is 2nd and so on ...
    int arr[10] = {2, -6, 6, 10, 11, 17};

    // Name of the array is the address of its first location
    cout << "Address of array is : " << arr << endl; // 0x61fe98
    // Also we can use & to find address of its first location
    cout << "Address of array is : " << &arr[0] << endl; // 0x61fe98

    cout << "1st element : " << *arr << endl;           // 2
    cout << "2st element : " << *(arr + 1) << endl;     // -6
    cout << "1st element + 1 : " << *(arr) + 1 << endl; // 3

    // internally compiler calculates the arr[i] as *(arr+i) == *(i+arr)

    cout << "2nd element : " << arr[2] << endl;     // 6
    cout << "2nd element : " << *(arr + 2) << endl; // 6
    cout << "2nd element : " << *(2 + arr) << endl; // 6
    cout << "2nd element : " << 2 [arr] << endl;    // 6

    // Differences between Arrays & Pointers

    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;  // 40 byte -- size of the entire array
    cout << sizeof(&temp) << endl; // 4 byte (size of the address of first element)

    // pointer p  will store the address of the array
    int *ptr = &temp[0];

    cout << sizeof(ptr) << endl;  // 4 byte (size of the address)
    cout << sizeof(*ptr) << endl; // 4 byte -- size of only first element of the array which is an integer
    cout << sizeof(*ptr) << endl; // 4 byte -- size of only first element of the array which is an integer

    int a[20] = {1, 2, 3, 5};
    cout << &a[0] << endl; // Address of a[0] 0x383hch

    int *p = &a[0];
    cout << &p << endl; // Address of p 0x3293he

    /*
    Symbol table cannot be changed
    arr = arr + 1 -- it will give us error because arr is a constant pointer
    arr is mapped with the address of the array in the symbol table & update operation in not allowed in Symbol table
    */

    // For Character arrays
    int ar[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl; // Oxe638g -- Address of the array
    cout << ch << endl;  // abcde -- values of the char array

    // Cout function is differently implimented for integer & Character array

    char *c = &ch[0];
    cout << c << endl; // it will print entire string until it finds a Null Character '/0'

    char char_temp = 'm';
    char *char_ptr = &char_temp;

    cout << char_ptr << endl; // mooj@ -- it will print everything in the subsequent memory until it finds a null character

    // How implimentation works
    /*
     char ch[6] = "abcdf";

     here firstly abcdf\0 is stored in a temporary memory and then it is copied to ch

     char *c = "abcde"; // Very Risky

     here firstly abcde is stored in a temporary memory & then c will point to the first charcters of that temporary memory

     This is Risky because while printing the values pointer may try to access a read only memory or etc
    */

    return 0;
}

// Pointers with Functions
void print(int *p)
{
    cout << p << endl;  // Ox3bc57f
    cout << *p << endl; // 5
}

void update(int *p)
{
    *p = *p + 1; // This will update the value at address p

    p = p + 1;
    cout << "inside : " << p << endl; // 0x61feb12
}

// int getSum(int *arr, int n) == int getSum(int arr[],int n) -- They both means the exactly same

/*
Its Benifit -- we can send a part of the array

like we can pass arr + 3 , arr + 5 in place of arr while calling the function
*/

int getSum(int *arr, int n)
{
    cout << "Size of arr : " << sizeof(arr) << endl; // 4 -- as this is a pointer not the entire array

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int value = 5;
    int *p = &value;

    print(p);

    /*
    The value of p is not changed after the update function

    main have created a pointer p which will contain the address of value

    when we call a function (pass by value) it creates a new pointer p in update function which will copy the content of original p -- means the address of value

    now in update function
    p = p + 1 -- will update its formal parameters but will not change the actual parameter

    hence , the original p remains same
    */

    cout << "Before : " << p << endl;  // 0x61feb8
    cout << "Before : " << *p << endl; // 5
    update(p);
    cout << "After : " << p << endl;  // 0x61feb8
    cout << "After : " << *p << endl; // 6

    // Arrays -- are always pass by reference
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = getSum(arr, 10);
    cout << "Sum is : " << sum << endl; // 55

    sum = getSum(arr + 3, 7);
    cout << "Sum is : " << sum << endl; // 49

    return 0;
}