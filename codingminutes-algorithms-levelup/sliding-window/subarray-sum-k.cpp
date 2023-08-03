/*
Problem Statement:
    Given an array of integers nums and an integer k, return the total
    number of subarrays whose sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an
    array.

    leetcode: https://leetcode.com/problems/subarray-sum-equals-k/
    vid: https://www.youtube.com/watch?v=fFVZt-6sgyo
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    we are creating a cumulative sum array from left to right. for each
    i of this array if i is equal to k then increase the count and if i-k
    is also present in the array before i index then number of times its present
    should be added to count. as the series can contains negative number
    so there can be multiple i-k present before i for example

    [2, -2, 1,  -1, 0] k=0
    [2, 0,  1,  0,  0]

    so for example at position i=3 i can create a sub array 0 to 3 that is
    giving a sum == k so increasing count by one, again at i=1 we get 0 so
    from 1 to 3 we will get another sub array equal to k so increasing the
    count.

    so here rather than counting number of i-k present before i index, we are storing
    i-k in a map with initialization to 1. so every time i-k is found in cumulative sum
    i-k value in map will be increase by 1.
*/
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefix;

    int count = 0;
    int cumulativeSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        cumulativeSum += nums[i];

        // starting from 0 to i index one sub array is possible
        if (cumulativeSum == k)
        {
            count++;
        }

        // if cumulativeSum - k is present means number of times
        // that value encountered can create a new sub array so adding count
        if (prefix.find(cumulativeSum - k) != prefix.end())
        {
            count += prefix[cumulativeSum - k];
        }

        prefix[cumulativeSum]++;
    }

    return count;
}

// only works for positive array and positive k
int positiveSubarraySum(const vector<int> &nums, const int k)
{
    int count = 0;

    int i = 0;
    int tempSum = 0;
    for (int j = 0; j < nums.size(); j++)
    {

        tempSum += nums[j];

        while (i < j && tempSum > k)
        {
            tempSum -= nums[i++];
        }

        if (tempSum == k)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    // pair<vector<int>, int> testCase = {
    //     vector<int>{1, 2, 3}, 3};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{1, 3, 2, 1, 4, 1, 3, 2, 1, 1}, 8};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{2, 1, 1}, 2};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{1}, 0};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{2, 2}, 0};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{-1, -1, 0}, 0};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{-1, -1, -1, 0}, -2};
    // pair<vector<int>, int> testCase = {
    //     vector<int>{-1, -1, 1}, 0};
    pair<vector<int>, int> testCase = {
        vector<int>{1, -1, 0}, 0};

    cout << subarraySum(testCase.first, testCase.second);
}