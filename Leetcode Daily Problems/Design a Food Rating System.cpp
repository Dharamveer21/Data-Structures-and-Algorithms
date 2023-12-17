#include <bits/stdc++.h>
using namespace std;

/*
Approach -- In change rating function i need to change rating for any given food , hence i need to take a map between food & rating , <string , int>

now we also need to return highest rated food for a given cuisine , we need to take a map between cusine & (rating , food) , it also must be sorted by rating
for that we can take a set or maxheap , it should be sorted on base of rating so we need to take the first element as rating , <string , set<pair<int,string>>>

we also need to keep track of the food and its cuisine with a map , <string,string> because when we change rating then we need to update it cuisine & its <rating , food> mapping to keep the max rating updated

now if two foods have same rating then in set it food which is lexographicaly smaller will come first , hence in order to get that string we need to give rating negative

e.g. -- (15,abc) , (16,shi) , (16,xyz) -- over function will return (16,xyz) but correct answer will be
(16,shi) as we need to get max rating but lexographically smallest string in that rating

thats why we put (-16,shi) , (-16,xyz) , (-15,abc) so always we just need to return 1st element
*/

class FoodRatings
{
private:
    unordered_map<string, int> food_rating;
    unordered_map<string, set<pair<int, string>>> cuisine_ratings_food;
    unordered_map<string, string> food_cuisine;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = (-1 * ratings[i]);

            food_rating[food] = rating;
            cuisine_ratings_food[cuisine].insert({rating, food});
            food_cuisine[food] = cuisine;
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = food_cuisine[food];
        int old_rating = food_rating[food];

        newRating = (-1 * newRating);
        cuisine_ratings_food[cuisine].erase({old_rating, food});

        food_rating[food] = newRating;
        cuisine_ratings_food[cuisine].insert({newRating, food});
    }

    string highestRated(string cuisine)
    {
        string highestRatedFood = cuisine_ratings_food[cuisine].begin()->second;
        return highestRatedFood;
    }
};

// TC : O(N * logN) + O(no. of times change rating is called * log(N))
// SC : O(N)

int main()
{

    return 0;
}