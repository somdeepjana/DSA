/*
Problem statement:
    Given an array of size atleast two, ind the smallest sub-array(smallest
    continuous part) that needs to be sorted in place so that entire input
    array becomes sorted.

    if the input array is already sorted then function should return [-1, -1],
    otherwise return the start and end index of smallest sub-array.

    similar leetcode: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solveSubArray(const vector<int> &arr)
{
    if (arr.size() <= 1)
        return {-1, -1};

    if (arr.size() == 2)
    {
        if (arr[0] <= arr[1])
            return {-1, -1};
        else
            return {0, 1};
    }

    int largestOutOfOrder = numeric_limits<int>::min();
    int smallestOutOfOrder = numeric_limits<int>::max();

    // figuring out largest and smallest problematic element because
    // smallest element will be giving the left side index same for other.
    for (int i = 1; i < arr.size(); i++)
    {
        // in a increasing series if previous element is greater then
        // that is a problematic elements
        if (arr[i - 1] > arr[i])
        {
            largestOutOfOrder = max(largestOutOfOrder, arr[i - 1]);
            smallestOutOfOrder = min(smallestOutOfOrder, arr[i]);
        }
    }

    if (smallestOutOfOrder == numeric_limits<int>::max())
    {
        return {-1, -1};
    }

    // index at which all the element to the left is smaller than the
    // smallest out of order is the left index
    int left_idx = 0;
    while (smallestOutOfOrder >= arr[left_idx])
    {
        left_idx++;
    }

    int right_idx = arr.size() - 1;
    while (largestOutOfOrder <= arr[right_idx])
    {
        right_idx--;
    }

    return {left_idx, right_idx};
}

int main()
{
    // vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    // vector<int> arr{1, 2, 3, 4, 5, 8, 7, 6, 9, 10, 11};
    // vector<int> arr{2, 1};
    // vector<int> arr{5, 4, 3, 2, 1};
    // vector<int> arr{1, 3, 2, 3, 3};
    // vector<int> arr{1, 1};
    vector<int> arr{2, 3, 3, 2, 4};

    for (const int &i : solveSubArray(arr))
    {
        cout << i << " ";
    }
}