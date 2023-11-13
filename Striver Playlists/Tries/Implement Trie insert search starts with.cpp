#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool isContians(char ch)
    {
        int ind = ch - 'a';
        return (this->links[ind] != NULL);
    }

    Node *getNext(char ch)
    {
        int ind = ch - 'a';
        return this->links[ind];
    }

    void putChar(char ch, Node *node)
    {
        int ind = ch - 'a';
        this->links[ind] = node;
    }

    void setEnd()
    {
        this->flag = true;
    }

    bool isEnd()
    {
        return (this->flag);
    }
};

// we need the root of the trie every time the operation is performed

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;

        // TC : O(len)
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (!node->isContians(ch))
            {
                node->putChar(ch, new Node());
            }

            node = node->getNext(ch);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (!node->isContians(ch))
            {
                return false;
            }

            node = node->getNext(ch);
        }

        return (node->isEnd());
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            char ch = prefix[i];

            if (!node->isContians(ch))
            {
                return false;
            }

            node = node->getNext(ch);
        }

        return true;
    }
};

int main()
{

    return 0;
}