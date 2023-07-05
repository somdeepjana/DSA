/*
Problem Statement:
    Implement a function that takes in a vector of integers, and returns
    a vector of the same length, where each element in the output array
    is equal to the product of every other number in the input array.
    Solve this problem without using division.

    In other words, the value at output[i] is equal to the product of
    every number in the input array other than input[i]. You can assume
    that answer can be stored inside int datatype and no-overflow will
    occur due to products.

    write algorithm with O(n) complexity without using division operator.

    leetcode: https://leetcode.com/problems/product-of-array-except-self/
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// less optimized solve with O(n) time and O(n) space complexity
vector<int> solveArrProd(const vector<int> &arr)
{
    int n = arr.size();

    int *forward = new int[n];
    int *backward = new int[n];

    int forwardProd = 1;
    int backwardProd = 1;

    // forward array contains all the element product from left and
    // backward contains all the element product from right
    for (int i = 0; i < n; i++)
    {
        forwardProd *= arr[i];
        forward[i] = forwardProd;

        backwardProd *= arr[n - 1 - i];
        backward[n - 1 - i] = backwardProd;
    }

    vector<int> result(n);
    for (int i = 1; i < n - 1; i++)
    {
        result[i] = forward[i - 1] * backward[i + 1];
    }
    result[0] = backward[1];
    result[n - 1] = forward[n - 2];

    return result;
}

// Optimizing the space by storing the multiplication result directly
// in the result array only don't multiply the current element rather
// keep it in a cumulative variable that will be the value of te next element.
vector<int> solveSpaceOptimized(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 1);

    int cumulate = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= cumulate;
        cumulate *= arr[i];
    }
    cumulate = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= cumulate;
        cumulate *= arr[i];
    }

    return result;
}

// same as above just reduce the multiple loops.
vector<int> solveCompleteOptimized(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 1);

    int forwardCumulate = 1;
    int backwardCumulate = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= forwardCumulate;
        forwardCumulate *= arr[i];

        result[n - 1 - i] *= backwardCumulate;
        backwardCumulate *= arr[n - 1 - i];
    }

    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    // vector<int> arr{4, 5};
    // vector<int> arr{-1, 1, 0, -3, 3};

    for (const int &i : solveSpaceOptimized(arr))
    {
        cout << i << ",";
    }
}