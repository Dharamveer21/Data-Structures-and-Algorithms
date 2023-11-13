#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

pair<int, int> all_possible_true_false(int left, int right, string &exp, vector<vector<pair<int, int>>> &all_true_false)
{
    if (left == right)
    {
        return {(exp[left] == 'T'), (exp[left] == 'F')};
    }

    if (all_true_false[left][right].first != -1 && all_true_false[left][right].second != -1)
    {
        return all_true_false[left][right];
    }

    int true_ans = 0, false_ans = 0;

    for (int expr = left + 1; expr < right; expr += 2)
    {
        pair<int, int> left_ans = all_possible_true_false(left, expr - 1, exp, all_true_false);
        pair<int, int> right_ans = all_possible_true_false(expr + 1, right, exp, all_true_false);

        int left_true = left_ans.first;
        int left_false = left_ans.second;

        int right_true = right_ans.first;
        int right_false = right_ans.second;

        if (exp[expr] == '&')
        {
            true_ans = ((true_ans + 0LL + ((left_true * 1LL * right_true) % M)) % M);
            false_ans = ((false_ans + (((left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M + 0LL + (left_false * 1LL * right_false) % M) % M)) % M);
        }

        if (exp[expr] == '|')
        {
            true_ans = ((true_ans + 0LL + (((left_true * 1LL * right_true) % M + 0LL + (left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M) % M)) % M);
            false_ans = ((false_ans + 0LL + ((left_false * 1LL * right_false) % M)) % M);
        }

        if (exp[expr] == '^')
        {
            true_ans = ((true_ans + 0LL + (((left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M) % M)) % M);
            false_ans = ((false_ans + 0LL + (((left_true * 1LL * right_true) % M + 0LL + (left_false * 1LL * right_false) % M) % M)) % M);
        }
    }

    return all_true_false[left][right] = {true_ans, false_ans};
}

int evaluateExp(string &exp)
{
    vector<vector<pair<int, int>>> all_true_false(exp.size(), vector<pair<int, int>>(exp.size(), {-1, -1}));
    pair<int, int> ans = all_possible_true_false(0, exp.size() - 1, exp, all_true_false);
    return ans.first;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    pair<int, int> all_true_false[n][n];

    for (int left = n - 1; left >= 0; left--)
    {
        for (int right = left; right < n; right++)
        {
            if (left == right)
            {
                all_true_false[left][right] = {(exp[left] == 'T'), (exp[left] == 'F')};
                continue;
            }

            int true_ans = 0, false_ans = 0;

            for (int expr = left + 1; expr < right; expr += 2)
            {
                pair<int, int> left_ans = all_true_false[left][expr - 1];
                pair<int, int> right_ans = all_true_false[expr + 1][right];

                int left_true = left_ans.first;
                int left_false = left_ans.second;

                int right_true = right_ans.first;
                int right_false = right_ans.second;

                if (exp[expr] == '&')
                {
                    true_ans = ((true_ans + 0LL + ((left_true * 1LL * right_true) % M)) % M);
                    false_ans = ((false_ans + (((left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M + 0LL + (left_false * 1LL * right_false) % M) % M)) % M);
                }

                if (exp[expr] == '|')
                {
                    true_ans = ((true_ans + 0LL + (((left_true * 1LL * right_true) % M + 0LL + (left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M) % M)) % M);
                    false_ans = ((false_ans + 0LL + ((left_false * 1LL * right_false) % M)) % M);
                }

                if (exp[expr] == '^')
                {
                    true_ans = ((true_ans + 0LL + (((left_true * 1LL * right_false) % M + 0LL + (right_true * 1LL * left_false) % M) % M)) % M);
                    false_ans = ((false_ans + 0LL + (((left_true * 1LL * right_true) % M + 0LL + (left_false * 1LL * right_false) % M) % M)) % M);
                }
            }

            all_true_false[left][right] = {true_ans, false_ans};
        }
    }

    return all_true_false[0][n - 1].first;
}

int main()
{

    return 0;
}