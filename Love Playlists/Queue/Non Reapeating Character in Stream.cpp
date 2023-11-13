#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        int n = A.size();
        vector<int> element_count(26, 0);
        queue<char> first_non_repeat;

        for (int i = 0; i < n; i++)
        {
            int ch = A[i] - 97;
            element_count[ch]++;

            if (element_count[ch] == 1)
            {
                first_non_repeat.push(A[i]);
            }

            if (first_non_repeat.empty())
            {
                A[i] = '#';
            }

            else
            {
                char ch = first_non_repeat.front();

                while (element_count[ch - 97] != 1)
                {
                    first_non_repeat.pop();
                       
                    if (first_non_repeat.empty())
                    {
                        A[i] = '#';
                        break;
                    }

                    ch = first_non_repeat.front();
                }
                
                if (first_non_repeat.empty())
                {
                    A[i] = '#';
                }

                else
                {
                    char ch = first_non_repeat.front();
                    A[i] = ch;
                }
            }
        }

        return A;
    }
};

int main()
{

    return 0;
}