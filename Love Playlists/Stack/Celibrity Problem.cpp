#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // we can use cilebrity row will be 0 all over and col equal to this row will 1 except cilebrity
    // brute force O(n2) approach
    int celebrity(vector<vector<int>> &M, int n)
    {
        int count = 0;
        int celibrity_row = -1;

        for (int i = 0; i < n; i++)
        {
            count = 0;

            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 0)
                {
                    count++;
                }
            }

            if (count == n)
            {
                celibrity_row = i;
                count = 0;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (M[i][celibrity_row] == 1)
            {
                count++;
            }
        }

        if (count == n - 1)
        {
            return celibrity_row;
        }

        return -1;
    }

    // O(n) approach where we use a stack and elimination method to find celibrity
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        int celibrity = -1;
        int row_cnt = 0;
        int col_cnt = 0;

        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() != 1)
        {
            int person1 = st.top();
            st.pop();
            int person2 = st.top();
            st.pop();

            int celib;

            if (M[person1][person2] == 0)
            {
                celib = person1;
            }

            else
            {
                celib = person2;
            }

            st.push(celib);
        }

        // check celibrity col --> everyone knows celibrity except him
        for (int row = 0; row < n; row++)
        {
            int celib = st.top();

            if (row != celib && M[row][celib] == 1)
            {
                row_cnt++;
            }
        }

        // check celibrity row --> celibrity knows no one
        for (int col = 0; col < n; col++)
        {
            int celib = st.top();

            if (M[celib][col] == 0)
            {
                col_cnt++;
            }
        }

        if (row_cnt == n - 1 && col_cnt == n)
        {
            celibrity = st.top();
        }

        return celibrity;
    }
};

int main()
{

    return 0;
}