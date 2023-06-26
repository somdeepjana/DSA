/*
Problem Statement:
    Given an unsorted array of integers nums, return the length of the longest band.
    A band is defined as a subsequence whose element can be reordered in such a manner that
    all the elemets appear in a consecutive(ie. difference of 1) order. A longest bad is
    the band which has maximum number of elemets.

    You must write an algorithm that runs in O(n) time.

    leetcode: https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solveLongestBand(const vector<int> &nums)
{
    // basic optimization for leetcode reduce time by 19ms
    ios_base::sync_with_stdio(false); // disable syncronization between c and c++ stream
    cin.tie(NULL);                    // stop flushing the buffer before each io operation

    unordered_map<int, bool> visited(nums.size());

    for (const int &i : nums)
        visited[i] = false;

    int maxLength = 0;

    for (const int &i : nums)
    {
        if (visited[i] == true)
            continue;

        int forwardTravel = i + 1;
        while (visited.find(forwardTravel) != visited.end())
        {
            visited[forwardTravel] = true;
            forwardTravel++;
        }

        int backwardTravel = i - 1;

        while (visited.find(backwardTravel) != visited.end())
        {
            visited[backwardTravel] = true;
            backwardTravel--;
        }
        maxLength = max(maxLength, forwardTravel - backwardTravel - 1);
    }

    return maxLength;
}

int main()
{
    // expected output 8
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << solveLongestBand(arr);
}