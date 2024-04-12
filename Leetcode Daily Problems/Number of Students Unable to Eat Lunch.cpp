#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We just have to simulate what has been told in the problem we will take a stack for sandwich and a
queue for students and do the simulation as told . But we have to keep the count of the students whom we send
back of the as they were not able to eat top sandwich . If at any point of time the number of students present
in the queue is equal to number of students we send back in the queue , then it is the stop point and the size
of the queue at that point is the number of students who are unable to eat any sandwich and return the ans .

The time complexity of this solution is --> ((n * (n+1)) / 4) = O(n * n) = O(n^2)
The reason is that consider a worst case when --> sandwich are 01010101 and students are 11110000
So, for each top of the sandwich the half the students must be traversed at that time --> Number of iteration is
are equal to : n/2 + n-1/2 + n-2/2 + n-3/2 + .... 1 = ((n * (n+1)) / 4) = O(n * n) = O(n^2) .
*/

class Solution
{
protected:
    void fillStack(vector<int> &sandwiches, stack<int> &sandwichesStack)
    {
        int sandwichCount = sandwiches.size();

        for (int ind = sandwichCount - 1; ind >= 0; ind--)
        {
            int sandwich = sandwiches[ind];
            sandwichesStack.push(sandwich);
        }
    }

    void fillQueue(vector<int> &students, queue<int> &studentsQueue)
    {
        int studentsCount = students.size();

        for (int ind = 0; ind < studentsCount; ind++)
        {
            int student = students[ind];
            studentsQueue.push(student);
        }
    }
                                                                            
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> studentsQueue;
        stack<int> sandwichesStack;
        int studentsSendBackCount = 0;

        fillStack(sandwiches, sandwichesStack);
        fillQueue(students, studentsQueue);

        while (!sandwichesStack.empty() && studentsQueue.size() != studentsSendBackCount)
        {
            int sandwich = sandwichesStack.top();
            sandwichesStack.pop();

            int student = studentsQueue.front();

            while (student != sandwich && studentsQueue.size() != studentsSendBackCount)
            {
                studentsQueue.pop();
                studentsQueue.push(student);

                studentsSendBackCount += 1;
                student = studentsQueue.front();
            }

            studentsQueue.pop();
        }

        int countOfStudentsUnableToEatSandwiches = studentsQueue.size();
        return countOfStudentsUnableToEatSandwiches;
    }
};

// TC : O(N * N) = O(N^2)
// SC : O(N + N) = O(N)

/*
Approach -- Actually we can see that if there are students present in the array corresponds to top sandwich of
the stack . Then it will eat it in future , hence at any point if there is no student present in the array which
can eat the top sandwich at that time the count of the students are unable to eat the sandwich . The main idea
is that the count is important not the order of the elements in the stack . Returnt the final count as ans .
*/

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int numberOfSandwiches = sandwiches.size();
        int countOfStudentsUnableToEatSandwiches = 0;

        for (int ind = 0; ind < numberOfSandwiches; ind++)
        {

        }

        return countOfStudentsUnableToEatSandwiches;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}