/*
Problem statement:
    Implement a function that takes in two non-empty arrays of integers,
    finds the pair of numbers (one from each array) who absolute difference
    is closest to zero, and returns a pair containing these two numbers,
    with the first number from array.
    Only one such pair will exist for the test.

    link: https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solveMinDiff(vector<int> &arr1, vector<int> &arr2)
{

    // sorting the array because equally smaller element will have
    // absolute deference near to zero.
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int min_diff = numeric_limits<int>::max();
    vector<int> result;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        int diff = abs(arr1[i] - arr2[j]);
        if (diff < min_diff)
        {
            min_diff = diff;
            result = {arr1[i], arr2[j]};
        }

        // comparing two element from array if one is bigger than the other
        // then increasing the smaller element will have the chance of getting
        // the absolute different nearer to zero. thats why increasing the i or j
        // to next element in the array if one of them element value is small.
        if (arr1[i] < arr2[j])
        {
            i++;
            continue;
        }

        j++;
    }

    return result;
}

int main()
{
    vector<int> arr1{23, 5, 10, 17, 30};
    vector<int> arr2{26, 134, 135, 14, 19};

    for (const int &i : solveMinDiff(arr1, arr2))
    {
        cout << i << ",";
    }
}