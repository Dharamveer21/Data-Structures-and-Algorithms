#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    Node *links[26];
    bool flag = false;

public:
    bool isContains(char ch)
    {
        int ind = ch - 'a';
        return (links[ind] != NULL);
    }

    void putChar(char ch, Node *node)
    {
        int ind = ch - 'a';
        this->links[ind] = node;
    }

    bool getEnd()
    {
        return (this->flag);
    }

    void setEnd()
    {
        this->flag = true;
    }

    Node *next(char ch)
    {
        int ind = ch - 'a';
        return (this->links[ind]);
    }
};

class Trie
{
private:
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
        }

        curr->setEnd();
    }

    bool checkAllPrefix(string &word)
    {
        Node *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            // just check if flag for every prefix is true or not
            curr = curr->next(ch);

            if (!curr->getEnd())
            {
                return false;
            }
        }

        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie *trie = new Trie();

    for (auto &word : a)
    {
        trie->insert(word);
    }

    string longest = "";

    for (auto &word : a)
    {
        if (word.length() > longest.length())
        {
            if ((trie->checkAllPrefix(word)))
            {
                longest = word;
            }
        }

        else if ((word.length() == longest.length()) && (word < longest))
        {
            if ((trie->checkAllPrefix(word)))
            {
                longest = word;
            }
        }
    }

    if (longest.empty())
    {
        return "None";
    }

    return longest;
}

int main()
{

    return 0;
}