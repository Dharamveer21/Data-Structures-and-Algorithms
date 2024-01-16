#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Use a vector as insertion in it is O(1) operation & we can find the random value in the O(1)
, in this method we use the concept of rand() function it will generate a random number
To use the number as index of any element , we can do rand() % size of vector . It will be between 0 & size - 1
Now the final part is deletion operation . We use a map to store the count of index of each element
We get the index of removal element in O(1) fromt the map . We swap the values of the element to be deleted
with the last element . Pop the last element & update the map during insertion & deletion
*/

class RandomizedSet
{
private:
    vector<int> arr;
    unordered_map<int, int> ElementIndex;

public:
    RandomizedSet()
    {
        arr.clear();
        ElementIndex.clear();
    }

    bool insert(int val)
    {
        if (ElementIndex.find(val) != ElementIndex.end())
        {
            return false;
        }

        int n = arr.size();
        ElementIndex[val] = n;

        arr.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (ElementIndex.find(val) == ElementIndex.end())
        {
            return false;
        }

        int index = ElementIndex[val];
        int lastElement = arr.back();

        ElementIndex[lastElement] = index;
        ElementIndex.erase(val);

        arr[index] = lastElement;
        arr.back() = val;
        arr.pop_back();

        return true;
    }

    int getRandom()
    {
        int n = arr.size();
        int randomIndex = ((rand()) % n);

        int val = arr[randomIndex];
        return val;
    }
};

// TC : O(1)
// SC : O(N)

int main()
{

    return 0;
}