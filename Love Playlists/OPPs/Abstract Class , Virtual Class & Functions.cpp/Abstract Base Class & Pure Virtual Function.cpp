#include <bits/stdc++.h>
using namespace std;

/*
Abstract base class is a class which has atleast one pure virtual function

Abstract class is a class which is made to be inherited , not for creating its own objects
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

    /*
     It is a do nothing funtion also known as pure virtual function -- which means if any class inherits this
     function , then it must have to overwrite in the derived class or else it will show error
    */
    virtual void display() = 0;
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
