#include <bits/stdc++.h>
using namespace std;

/*in this method we will never encounter any duplicate substring*/

class Node
{
    Node *links[26];

public:
    bool isContains(char ch)
    {
        int ind = ch - 'a';
        return (this->links[ind] != NULL);
    }

    void put(char ch, Node *node)
    {
        int ind = ch - 'a';
        this->links[ind] = node;
    }

    Node *next(char ch)
    {
        int ind = ch - 'a';
        return (this->links[ind]);
    }
};

int countDistinctSubstrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();

    for (int i = 0; i < s.length(); i++)
    {
        Node *node = root;

        for (int j = i; j < s.length(); j++)
        {
            char ch = s[j];

            if (!(node->isContains(ch)))
            {
                // there is no substring with this as its last element
                cnt++;
                node->put(ch, new Node());
            }

            node = node->next(ch);
        }
    }

    return (cnt + 1);
}

int main()
{

    return 0;
}