#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we use doubly linked list for it , we also use a map to store address of each node
When get is called , we search the key in map & returns it . We delete it from doubly linked list
Insert it at the begining , the last elements are least recently used one

When put is called called , we check size of the Cache & insert element at the beginning
We delete the element from the last if capacity has reached in the cache size
*/

class LRUCache
{
private:
    int capacity;
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;

protected:
    void makeRecentlyUsed(int key)
    {
        list<int>::iterator keyAddress = mp[key].first;
        dll.erase(keyAddress);

        dll.push_front(key);
        list<int>::iterator newAddress = dll.begin();
        mp[key].first = newAddress;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        makeRecentlyUsed(key);
        return (mp[key].second);
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
            return;
        }

        dll.push_front(key);
        list<int>::iterator keyAddress = dll.begin();

        mp[key] = {keyAddress, value};
        capacity--;

        if (capacity < 0)
        {
            int keyToBeDeleted = dll.back();
            mp.erase(keyToBeDeleted);
            dll.pop_back();
            capacity++;
        }
    }
};

// TC : O(1)
// SC : O(N)

int main()
{

    return 0;
}