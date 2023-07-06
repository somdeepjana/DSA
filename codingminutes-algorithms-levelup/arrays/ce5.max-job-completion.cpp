/*
Problem Statement:
    Given an integer N denoting number of jobs and a matrix ranges[]
    consisting of a range [start day, end day] for each job within which
    it needs to be completed, the task is to find the maximum possible
    jobs that can be completed.

    Input: N = 5, Ranges = {{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}}
    Output: 5
    Explanation: Job 1 on day 1, Job 4 on day 2, Job 5 on day 3, Job 2 on day 4, Job 3 on day 5


    link: https://www.geeksforgeeks.org/maximize-jobs-that-can-be-completed-under-given-constraint/
*/

#include <iostream>
#include <vector>
#include <algorithm>
// #include <utility>

using namespace std;

// sort the pair vector with respect to the end time(pair.second) in increasing order
bool secondComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int countActivites(vector<pair<int, int>> &activities)
{
    int completed = 0;
    int currentTime = 0;

    // sorting based on end time so smallest end time job completes faster and earlier.
    sort(activities.begin(), activities.end(), secondComparator);

    for (const pair<int, int> &i : activities)
    {
        // if the starting time of the job is less than previous job end time
        // then that job cannot be scheduled.
        if (i.first >= currentTime)
        {
            completed++;
            currentTime = i.second;
        }
    }

    return completed;
}

int main()
{
    vector<pair<int, int>> activities{
        {7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

    cout << countActivites(activities);
}