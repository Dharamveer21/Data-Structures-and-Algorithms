#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// using open function

int main()
{
    ofstream out;
    out.open("Sample File.txt");
    out << "This is my file"; // This will write the "text" in the file
    out.close();

    string str;
    ifstream in;
    in.open("Sample File.txt");

    // eof() tells true if file is ended
    // means there are no more text in the file , we are at the last otherwise false

    while (in.eof() == 0)
    {
        getline(in, str);
        cout << str << endl;
    }

    in.close();
    return 0;
}