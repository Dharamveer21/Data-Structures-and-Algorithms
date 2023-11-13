#include <bits/stdc++.h>
using namespace std;

/* Reference Variable -- same memory location having differnt names
we need reference variable for calling functions by reference
*/

// This is a bad practice because the variables ans,num,a are all local variables the will be destroyed by the function closing so there may me some garbage value in the place of their location which we are trying to access or it may be allocated to some other variable which we could have changed
int &func(int a)
{
    int num = a;
    int &ans = num;
    return ans;
}

// same issue as above
int *funp(int a)
{
    int *num = &a;
    return num;
}

void update1(int n) // it is call by value -- when a copy of the actual parameters is created
{
    n++;
}

void update2(int &n) // it is call by reference -- when a new name is given to actual paramters memory location
{
    n++;
}

int getSum(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int i = 5;
    int &j = i; // Created a reference variable

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    i++;
    cout << j << endl;

    int nt = 5;

    cout << "Before : " << nt << endl; // 5
    update1(nt);
    cout << "After : " << nt << endl; // 5

    cout << "Before : " << nt << endl; // 5
    update2(nt);
    cout << "After : " << nt << endl; // 6

    /*
    we should not allocate the size of the array on runtime -- it is a bad practice ,  we should have known it on compile time 
    int n;
    cin >> n;
    int arr[n]; --> This is static memory which we got in stack memory

    Memory has two parts : Stack (Static) & Heap(Dynamic)

    in case : the user demand the a large dynamic memory on runtime which would not be available at that time in stack the program will crash

    so for that purpose we use heap memory for dynamic alloction of memory , heap is usually larger in size then stack
    */

    // For Dynamic Memory Allocation we use new keyword
    // There is no name for heap memory it only returns the starting address of the memory allocated in heap so we will use pointers for the same
    // The dynamic variable will be in heap memory but pointer pointing to it is in stack memory -- So Total memory used is sizeof(dynamic variable in heap) + sizeof(Static pointer in stack)

    char ch = 'q'; // 1 byte
    cout << sizeof(ch) << endl;

    char *c = &ch; // 4 byte
    cout << sizeof(c) << endl;

    int n;
    cin >> n;

    // variable size array
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // arr[i] = *(arr + i)
    }

    int ans = getSum(arr, n);
    cout << "Sum is : " << ans << endl;

    // Case 1 : Create variable in Infinite Loop in Static Memory
    while (true)
    {
        int i = 5; // At a instant of time it only takes 4 bytes of memory & on next iteration the memory gets free itself
    }

    // Case 2 : Create variable in Infinite Loop in Dynamic Memory
    while (true)
    {
        int *ptr = new int; // In Each iteration it takes a new memory location & it will not get free automatically , we have to free it manually by using delete keyword

        delete ptr; // for variable deletion
    }

    delete[] arr; // for array deletion

    return 0;
}