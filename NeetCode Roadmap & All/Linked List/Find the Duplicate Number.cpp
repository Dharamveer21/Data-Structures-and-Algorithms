#include <bits/stdc++.h>
using namespace std;

/*
Approach -- This is a special problem where we can observe that elements are [1,n] whereas size is (n+1) means
atleast 1 element is repeated twice or more than twice . Here we can imagine a list which is from index of
array to its value . Here we know that index are from (0 to n) so the starting index is 0 from which we start
and go to index equal to value at 0 . We treat value at a index as the new index . If atleast one element is
repeated in the array then there must be a cycle in this imaginary list between index and values . It is obvious
that list starts from 0 and no value can be zero so the traversal will never return to 0 and finally will fall
in a loop as all the rest of values are indexes and traversal will fall in the loop .

Here is a very important point to notice that the as there is a loop in the list we know that 0 cannot be the
starting point means the list is of the given type : consider nums as --> 1 2 3 4 5 3

This is the mapping of index and the value at the particular index .

                          0 -- 1 -- 2 -- 3 -- 4 -- 5 --|
                                         |             |
                                         |-------------|

Here , 0 can never be the starting point of loop , so the starting point of the loop is the repeating element
because if is pointed by 2 different indexes :
                                            i)  first from the side of the 0
                                            ii) other from the ending of the loop

means this element is pointed by 2 indexes means this element is present at two different indexes so its the
repeating element .

So , it becomes a simple problem of finding the starting point of cycle in the linked list for which we will
use Tortoise & Hair method of slow & fast pointers .

We will start the slow & fast pointers from value at index 0 and move slow 1 step forward while fast 2 steps
forward and we know if there is a cycle they will eventually meet due to relative speed of 1 step at a time
between them . Now , when they meet we initialise slow pointer to starting index (value at 0 index) and move
both fast & slow pointers 1 step at a time they will eventually meet at the starting point of the list or
we can say that at the repearting number in the given array .

The proof that they will meet at the starting point of the list is a mathematical proof . Consider a list

                          A-----------B------------C
                                      |            |
                                      |------------D

When we start slow and fast pointer from A then they will finally meet at D . So, we can say :

L1 -- length between A and B (starting point of the list)
L2 -- length between B and D via C and L3 -- length between D and B not via C

we know that fast moves twice than the slow pointer because it is two time more faster than slower one .
Cycle length L = L2 + L3

Distance by slow : L1 + L2 , Distance by fast : L1 + n(L2 + L3) + L2 , n is the number of rounds fast will
take of the loop before meeting with slow pointer . Now matheatically : 2 Ds = Df

2 (L1 + L2) = L1 + nL + L2 ==> 2 L1 + 2 L2 = L1 + (n-1)L + L2 + L3 + L2 ==> L1 = (n-1)L + L3

here , we can see that when we put slow again at start (A) then it will move a distance a distance L1 to reach
starting of the loop (B) and in the same time fast will make (n-1) rounds of cycle and move L3 which is distance
between D and B not via C and reach point B (as proved in the equation) , hence both meet at the starting point
of the list . So , we can say that it is the repeating element and return its value .
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[nums[0]], slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        int repeatedVal = slow;
        return repeatedVal;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}