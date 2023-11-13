#include <bits/stdc++.h>
using namespace std;

// Number of Subsequences with given sum
class Solution
{
public:
    int subsequence_given_sum(int ind, int sum, vector<int> &nums)
    {
        if (sum == 0)
        {
            return 1;
        }

        if (sum < 0 || ind > nums.size())
        {
            return 0;
        }

        int total = 0;
        total += subsequence_given_sum(ind + 1, sum - nums[ind], nums);
        total += subsequence_given_sum(ind + 1, sum, nums);

        return total;
    }

    int sequence(vector<int> &nums, int sum)
    {
        int ans = subsequence_given_sum(0, sum, nums);
        return ans;
    }
};

int main()
{
    Solution *obj = new Solution;

    vector<int> nums(10);
    int sum;

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    cin >> sum;
    cout << obj->sequence(nums, sum) << endl;

    return 0;
}

// Print all Subsequences with given sum
class Solution
{
public:
    void subsequence_given_sum(int ind, vector<int> &subsequence, int sum, vector<int> &nums)
    {
        if (ind > nums.size())
        {
            if (sum == 0)
            {
                for (auto val : subsequence)
                {
                    cout << val << " ";
                }

                cout << endl;
            }

            return;
        }

        // we don't include ind
        subsequence_given_sum(ind + 1, subsequence, sum, nums);

        // we include ind
        int num = nums[ind];
        subsequence.push_back(num);
        subsequence_given_sum(ind + 1, subsequence, sum - num, nums);
        subsequence.pop_back();
    }

    void sequence(vector<int> &nums, int sum)
    {
        vector<int> subsequence;
        subsequence_given_sum(0, subsequence, sum, nums);
    }
};

int main()
{
    Solution *obj = new Solution;

    vector<int> nums(10);
    int sum;

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    cin >> sum;
    obj->sequence(nums, sum);

    return 0;
}

// Print any one subsequence with given sum
class Solution
{
public:
    bool subsequence_given_sum(int ind, vector<int> &subsequence, int sum, vector<int> &nums)
    {
        if (ind > nums.size())
        {
            if (sum == 0)
            {
                for (auto val : subsequence)
                {
                    cout << val << " ";
                }

                return true;
            }

            return false;
        }

        int num = nums[ind];
        subsequence.push_back(num);

        if (subsequence_given_sum(ind + 1, subsequence, sum - num, nums))
        {
            return true;
        }

        subsequence.pop_back();

        if (subsequence_given_sum(ind + 1, subsequence, sum, nums))
        {
            return true;
        }

        return false;
    }

    bool sequence(vector<int> &nums, int sum)
    {
        vector<int> subsequence;
        bool ans = subsequence_given_sum(0, subsequence, sum, nums);
        cout << endl;
        return ans;
    }
};

int main()
{
    Solution *obj = new Solution;

    vector<int> nums(10);
    int sum;

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    cin >> sum;
    cout << obj->sequence(nums, sum) << endl;

    return 0;
}
