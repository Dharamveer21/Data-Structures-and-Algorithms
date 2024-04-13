#include <bits/stdc++.h>
using namespace std;

// Sorting and Circular Indexing
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int currCard = 0, currPos = 0;
        int numberOfCards = deck.size();
        bool skipTheCurrPosition = false;

        sort(deck.begin(), deck.end());
        vector<int> result(numberOfCards, 0);

        while (currCard < numberOfCards)
        {
            int numberOfCurrCard = deck[currCard];

            if (result[currPos] == 0)
            {
                if (skipTheCurrPosition == false)
                {
                    currCard = currCard + 1;
                    skipTheCurrPosition = true;
                    result[currPos] = numberOfCurrCard;
                }

                else
                    skipTheCurrPosition = false;
            }

            currPos = ((currPos + 1) % numberOfCards);
        }

        return result;
    }
};

// TC : O(N * log(N))
// SC : O(N)

// Simulation using a Queue
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        queue<int> queueForSimulation;
        int numberOfCards = deck.size();
        int currCard = 0, currCardIndex = 0;

        sort(deck.begin(), deck.end());
        vector<int> result(numberOfCards, 0);

        for (int ind = 0; ind < numberOfCards; ind++)
            queueForSimulation.push(ind);

        while (!queueForSimulation.empty())
        {
            currCardIndex = queueForSimulation.front();
            queueForSimulation.pop();

            if (!queueForSimulation.empty())
            {
                int nextCurrCardIndex = queueForSimulation.front();
                queueForSimulation.push(nextCurrCardIndex);
                queueForSimulation.pop();
            }

            int numberOfCurrCard = deck[currCard++];
            result[currCardIndex] = numberOfCurrCard;
        }

        return result;
    }
};

// TC : O(N * log(N))
// SC : O(N)

int main()
{
    return 0;
}