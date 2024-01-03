#include <bits/stdC++.h>
using namespace std;

/*
Approach -- find the count of 1 in each row of bank , use a prev variable to get count of '1' in the previous
row having count of '1' > 0 . When we get to new row with count of '1' > 0 , move curr to this row
We calculate curr * prev & find the next row with count of '1' > 0 , then point prev to curr & curr to next
*/

class Solution
{
public:
    int countString1(string &str)
    {
        int count = 0;

        for (char &ch : str)
        {
            count = count + (ch == '1');
        }

        return count;
    }

    int numberOfBeams(vector<string> &bank)
    {
        int rows = bank.size(), totalBeams = 0;
        int prevSecurityDevices = 0;
        int currSecurityDevices = 0;

        for (int row = 0; row < rows; row++)
        {
            int count = countString1(bank[row]);

            if (count > 0)
            {
                prevSecurityDevices = currSecurityDevices;
                currSecurityDevices = count;
                 
                int beams = prevSecurityDevices * currSecurityDevices;
                totalBeams += beams;
            }
        }

        return totalBeams;
    }
};

// TC : O(M * N)
// SC : O(1)

int main()
{
    return 0;
}