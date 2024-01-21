#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
A Program can read a particular file
A Program can write into a particular file

input stream -- to get data from file
output stream -- to put data into file
*/

/*
The useful classes for working with files in c++ are :
1. fstream --> base class

2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreambase
*/

/*
There are two ways to open a files
1. using the constructor
2. using the member function open() of the class
*/

int main()
{
    string st1 = "Harry Bhai", st2;

    // Opening files using constructor & writing it
    ofstream out("Sample File.txt"); // Write operation
    out << st1;                      // This will write the content of st into in the file

    out.close();

    // Opening files using constructor & reading it
    ifstream in("Sample File.txt"); // Write operation
    in >> st2;                      // This will put the content of files into st in the file

    /*
    But in ifstream , this will stop when it get space or newline , so use getline function instead to get one whole line
    If we need mutliple lines we can use loop
    */

    getline(in, st2); // first line comes in "st2"
    getline(in, st2); // second line comes in "st2"

    cout << st2 << endl;

    in.close();

    return 0;
}

// We should close a file after using it , as a good practice