#include <bits/stdc++.h>
using namespace std;

/*
Consider class A , B , C & D

When we do hierarchical inheritance
Then multiple inheritance then --

          A
         / \
        B  C
        \ /
         D

Class D will have multiple copies of data of class A , which creates error as two variable & functions having same name
To avoid this ambiguity we use virtual class inheritance

So, to resolve this , we can derive B & C from Virtual Base Class A
*/

/*
base --> derived

1. Student --> Test
2. Student --> Sports
3. Test --> Result
4. Sports --> Result
*/

class Student
{
private:
    int roll_no;

public:
    void set_number(int a)
    {
        roll_no = a;
    }

    void print_number(void)
    {
        cout << "Your Roll number is : " << roll_no << endl;
    }
};

class Test : virtual public Student
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void print_marks(void)
    {
        cout << "Your result is here : " << endl
             << "Maths : " << maths << endl
             << "Physics : " << physics << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }

    void print_score()
    {
        cout << "Your PT Score is : " << score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display(void)
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();

        cout << "Your total score is : " << total << endl;
    }
};

int main()
{
    Result harry;

    harry.set_number(4200);
    harry.set_marks(78.9, 99.5);
    harry.set_score(9);

    harry.display();

    return 0;
}