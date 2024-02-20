#include <bits/stdc++.h>
using namespace std;

/*
Approach -- In this problem we have to just implement what is being asked to do in the question but the main
problem is that how we will efficiently find if any room is free to assign a meeting and if no one is free then
to which room we should assign the meeting . We will use two minHeaps , first will store freeTime for a room and
second heap will store the freeRooms numbers . We will initialise the freeRooms heap will all rooms initially .

Now , when we go for any meeting while traversing we have to perform 3 operations :-
1. check how many rooms got freed before current meetings & assign them to freeRooms heap .
2. if there is any freeRoom assign the room for current meeting and update the first heap with finishTime & room
3. if there is no freeRoom then pick the earliest finish finsihTime room from first heap & add the duration of current
meeting to get the new finish finsihTime , then put it in the heap again .

During operation 2 & 3 , we are assigning meetings to rooms so increse the booking count for these rooms
Finally find the maximum booking count & return its room number .
*/

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> bookingCount(n, 0);
        int mostBooking = 0, mostBookedRoom = 0;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> earliestFinishTime;

        sort(meetings.begin(), meetings.end());

        for (int room = 0; room < n; room++)
        {
            freeRooms.push(room);
        }

        for (vector<int> &meeting : meetings)
        {
            int startTime = meeting[0];
            int endTime = meeting[1];
            int duration = endTime - startTime;

            // free the rooms
            while (!earliestFinishTime.empty())
            {
                long long finishTime = earliestFinishTime.top().first;
                int room = earliestFinishTime.top().second;

                // no room is free
                if (finishTime > startTime)
                {
                    break;
                }

                earliestFinishTime.pop();
                freeRooms.push(room);
            }

            // assign a freeRooms
            if (!freeRooms.empty())
            {
                int room = freeRooms.top();
                freeRooms.pop();

                earliestFinishTime.push({(endTime * 1LL), room});
                bookingCount[room]++;
                continue;
            }

            // if no room is free
            long long earlistFreeTime = earliestFinishTime.top().first;
            int earlistFreeRoom = earliestFinishTime.top().second;

            earliestFinishTime.pop();
            long long newFreeTime = earlistFreeTime + 0LL + duration;

            earliestFinishTime.push({newFreeTime, earlistFreeRoom});
            bookingCount[earlistFreeRoom]++;
        }

        // most booked room
        for (int room = n - 1; room >= 0; room--)
        {
            int booking = bookingCount[room];
            mostBooking = max(mostBooking, booking);

            mostBookedRoom = ((booking == mostBooking) ? room : mostBookedRoom);
        }

        return mostBookedRoom;
    }
};

// M -- number of meetings , N -- number of rooms
// TC : O(N + M * log(N) + N) = O(M * log(N))
// SC : O(N)

int main()
{

    return 0;
}