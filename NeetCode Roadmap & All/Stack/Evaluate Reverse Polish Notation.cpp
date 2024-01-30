#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We will use a stack here , We add the numbers in the stack & if we get a operator we perform the
operation with the operands in the stack & then push the answer in the stack again
*/

class Solution
{
protected:
    bool isValidOperator(string &str)
    {
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            return true;
        }

        return false;
    }

    int evaluate(int firstOperand, int secondOperand, char binaryOperator)
    {
        int result = 0;

        switch (binaryOperator)
        {
        case '+':
            result = firstOperand + secondOperand;
            break;

        case '-':
            result = firstOperand - secondOperand;
            break;

        case '*':
            result = firstOperand * secondOperand;
            break;

        case '/':
            result = firstOperand / secondOperand;
            break;
        }

        return result;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        int result = 0;
        stack<string> st;
        int n = tokens.size();

        for (int ind = 0; ind < n; ind++)
        {
            string &str = tokens[ind];
            int len = str.length();

            if (len == 1 && isValidOperator(str))
            {
                char &binaryOperator = str[0];

                int secondOperand = stoi(st.top());
                st.pop();

                int firstOperand = stoi(st.top());
                st.pop();

                int value = evaluate(firstOperand, secondOperand, binaryOperator);
                st.push(to_string(value));
                continue;
            }

            st.push(str);
        }

        result = stoi(st.top());
        return result;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}