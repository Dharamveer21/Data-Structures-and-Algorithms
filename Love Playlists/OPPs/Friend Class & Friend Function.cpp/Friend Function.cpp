#include <bits/stdc++.h>
using namespace std;

/*
In friend function the object can use the private data members of their class
*/

class Complex
{
private:
    int realPart = 0, complexPart = 0;
    friend void addComplex(Complex &, Complex &);

public:
    int setVal(int realPart, int complexPart)
    {
        this->realPart = realPart;
        this->complexPart = complexPart;
    }
};

void addComplex(Complex &c1, Complex &c2)
{
    Complex c3;
    c3.realPart = c1.realPart + c2.realPart;
    c3.complexPart = c1.complexPart + c2.complexPart;
    
    cout << "New Number is : " << c3.realPart << " + " << c3.complexPart << "i" << endl;
}

int main()
{
    Complex c1, c2;

    c1.setVal(3, 4);
    c2.setVal(5, 6);

    addComplex(c1, c2);

    return 0;
}