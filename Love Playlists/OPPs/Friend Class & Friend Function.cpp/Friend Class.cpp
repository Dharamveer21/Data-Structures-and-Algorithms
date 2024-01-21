#include <bits/stdc++.h>
using namespace std;

/*
 Here class Complex has friend Calculator , so private data of complex is
 accessable by functions of calculator

 If A is friend of B , that does not mean B is friend of A
*/

// Forward Decelaration
class Complex;

class Calculator
{
public:
    void addComplex(Complex &, Complex &);
    void subComplex(Complex &, Complex &);
};

class Complex
{
private:
    int realPart = 0, complexPart = 0;

    // There are two ways to make friend the member functions of the class Calculator

    // Way 1 -- making them friend individually
    friend void Calculator::addComplex(Complex &, Complex &);
    friend void Calculator::subComplex(Complex &, Complex &);

    // Way 2 -- making the class directly friend
    friend class Calculator;

public:
    int setVal(int realPart, int complexPart)
    {
        this->realPart = realPart;
        this->complexPart = complexPart;
    }
};

void Calculator::addComplex(Complex &c1, Complex &c2)
{
    Complex c3;
    c3.realPart = c1.realPart + c2.realPart;
    c3.complexPart = c1.complexPart + c2.complexPart;

    cout << "Sum is: " << c3.realPart << " + " << c3.complexPart << "i" << endl;
}

void Calculator::subComplex(Complex &c1, Complex &c2)
{
    Complex c3;
    c3.realPart = c1.realPart - c2.realPart;
    c3.complexPart = c1.complexPart - c2.complexPart;

    cout << "Difference is: " << c3.realPart << " + " << c3.complexPart << "i" << endl;
}

int main()
{
    Complex c1, c2;

    c1.setVal(10, 11);
    c2.setVal(5, 6);

    Calculator calc;
    calc.addComplex(c1, c2);
    calc.subComplex(c1, c2);

    return 0;
}
