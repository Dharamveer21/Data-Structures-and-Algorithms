#include <bits/stdc++.h>
using namespace std;

/*
Rules for virtual function :
1. They cannot be static
2. They are accessed by object pointers
3. Virtual functions can be a friend of another class
4. A virtual function in base class might not be used
5. If a virtual function is defined in the base class & not redefined in derived class
then it will run this same virtual function like normal function
*/

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }

    virtual void display() {}
};

class CWHVideo : public CWH
{
    float videoLength;

public:
    CWHVideo(string s, float r, float vl) : CWH(s, r)
    {
        videoLength = vl;
    }

    void display()
    {
        cout << "This is an amazing video with title " << title << endl;
        cout << "Rating : " << rating << " out of 5 stars" << endl;
        cout << "Length of the video is : " << videoLength << " minutes" << endl;
    }
};

class CWHText : public CWH
{
    int words;

public:
    CWHText(string s, float r, int wc) : CWH(s, r)
    {
        words = wc;
    }

    void display()
    {
        cout << "This is an amazing text with title " << title << endl;
        cout << "Rating : " << rating << " out of 5 stars" << endl;
        cout << "Length of the text is : " << words << " words" << endl;
    }
};

int main()
{
    string title = new char[30];
    float rating, vlen;
    int words;

    // for code with harry video
    title = "Django Tutorial video";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djVideo(title, rating, vlen);

    djVideo.display();

    // for code with harry text
    title = "Django Tutorial text";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);

    djText.display();

    CWH *tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    tuts[1]->display();

    return 0;
}