#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[26];
    int cntEqualTo = 0;
    int cntStartWith = 0;

    // memeber functions
    bool isContains(char ch)
    {
        int ind = ch - 'a';
        return (this->link[ind] != NULL);
    }

    Node *next(char ch)
    {
        int ind = ch - 'a';
        return (this->link[ind]);
    }

    void putChar(char ch, Node *node)
    {
        int ind = ch - 'a';
        this->link[ind] = node;
    }

    void setEnd()
    {
        this->cntEqualTo += 1;
    }

    int getStartsWith()
    {
        return (this->cntStartWith);
    }

    int getEqualTo()
    {
        return (this->cntEqualTo);
    }

    void IncrementStartsWith()
    {
        this->cntStartWith++;
    }

    void DecrementStartWith()
    {
        this->cntStartWith--;
    }

    void IncrementEqualTo()
    {
        this->cntEqualTo++;
    }

    void DecrementEqualTo()
    {
        this->cntEqualTo--;
    }
};

// we do need the root of the try every time
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (!(curr->isContains(ch)))
            {
                curr->putChar(ch, new Node());
            }

            curr = curr->next(ch);
            curr->IncrementStartsWith();
        }

        curr->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (!(curr->isContains(ch)))
            {
                return 0;
            }

            curr = curr->next(ch);
        }

        return (curr->getEqualTo());
    }

    int countWordsStartingWith(string &word)
    {
        Node *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (!(curr->isContains(ch)))
            {
                return 0;
            }

            curr = curr->next(ch);
        }

        return (curr->getStartsWith());
    }

    void erase(string &word)
    {
        Node *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            curr->DecrementStartWith();
            curr = curr->next(ch);
        }

        curr->DecrementStartWith();
        curr->DecrementEqualTo();
    }
};

int main()
{
    return 0;
}