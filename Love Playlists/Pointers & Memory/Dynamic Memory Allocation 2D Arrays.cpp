#include <bits/stdc++.h>
using namespace std;

/*
A 2D Array of size rows ,cols is int arr[rows][cols]
here , it is also understood as there are total 'rows' number of arrays each of size 'cols'

so if we want to create a dynamic 2D Array of size m , n

we have to create total m 1D Arrays each of size n
& for those arrays we need to create an array of m pointers in heap which is pointed by a pointer in stack
e.g. -->

int **arr = new int*[]; // array of pointers

for each pointer we need to create an array of integers
ptr = new int[];
*/

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int **arr = new int *[rows]; // arrays of pointers which points to each array of integers

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols]; // each array of integers
    }

    // input
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    // we always have to free the heap memory after the execution of the program

    // Clear the memory of the each integer array first
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    // Clear the memory of the array of pointers
    delete[] arr;

    return 0;
}