/*
Problem Statement:
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == given sum.
    Notice that the solution set must not contain duplicate triplets. and all he triplets are in order.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// start parameter cannot be zero. it will not cause problem because it's being called
// from solveTriplet function which will always send start from 1 to N.
vector<vector<int>> solveSortedPairSum(vector<int> &arr, int sum, int start)
{
    int i = start;
    int j = arr.size() - 1;
    int tempSum = 0;

    vector<vector<int>> result;

    while (i < j)
    {
        tempSum = arr[i] + arr[j];
        if (tempSum == sum)
        {

            result.emplace_back(vector<int>{arr[start - 1], arr[i], arr[j]});
            i++;
            j--;
            continue;
        }
        if (tempSum > sum)
        {

            j--;
            continue;
        }

        i++;
    }
    return result;
}

vector<vector<int>> solveTriplet(vector<int> &arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    for (int i = 0; i < arr.size(); i++)
    {
        for (const vector<int> &pairResult : solveSortedPairSum(arr, sum - arr[i], i + 1))
        {
            result.emplace_back(pairResult);
        }
    }

    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int target = 18;

    for (const vector<int> &triplet : solveTriplet(arr, target))
    {
        for (const int &ele : triplet)
        {
            cout << ele << ",";
        }

        cout << endl;
    }
}