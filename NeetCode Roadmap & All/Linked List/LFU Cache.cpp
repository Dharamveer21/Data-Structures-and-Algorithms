#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we have to use a map for key & its address node in doubly linked list
Also we need to increment a counter for a key if we do get to push any operation with that key

So , we will also take a map between counter & a doubly linked list . It will store the doubly
linked list for that counter . Each doubly linked list for a particular counter is operated like LRU Cache.

push in front & deletion from the last . We have to store key,value & its counter in node of doubly linked list
Key point is when capacity is reached we have to delete first & then enter the new one otherwise in some cases
it may delete our just inserted node
*/

class LFUCache
{
private:
    int capacity;
    unordered_map<int, list<pair<int, pair<int, int>>>::iterator> cache;
    map<int, list<pair<int, pair<int, int>>>> cacheCount;

protected:
    void makeRecentlyUsed(int key)
    {
        auto keyAddress = cache[key];

        int value = keyAddress->second.first;
        int counter = keyAddress->second.second;

        cacheCount[counter].erase(keyAddress);

        if (cacheCount[counter].empty())
        {
            cacheCount.erase(counter);
        }

        counter = counter + 1;
        cacheCount[counter].push_front({key, {value, counter}});

        auto newAddress = cacheCount[counter].begin();
        cache[key] = newAddress;
    }

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        makeRecentlyUsed(key);

        auto keyAddress = cache[key];
        int value = keyAddress->second.first;
        return value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            makeRecentlyUsed(key);
            auto keyAddress = cache[key];
            keyAddress->second.first = value;
            return;
        }

        if (capacity == 0)
        {
            auto toRemove = cacheCount.begin();
            int counter = toRemove->first;

            int keyToBeDeleted = cacheCount[counter].back().first;
            cacheCount[counter].pop_back();
            cache.erase(keyToBeDeleted);

            if (cacheCount[counter].empty())
            {
                cacheCount.erase(counter);
            }

            capacity++;
        }
        
        cacheCount[1].push_front({key, {value, 1}});
        auto keyAddress = cacheCount[1].begin();
        cache[key] = keyAddress;
        capacity--;
    }
};

// TC : O(1)
// SC : O(N)

int main()
{

    return 0;
}