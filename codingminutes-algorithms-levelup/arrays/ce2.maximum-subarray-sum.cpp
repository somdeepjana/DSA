/*
Problem statement:
    Given an array arr[] of size N. The task is to find the sum of the
    contiguous subarray within a arr[] with the largest sum.(Kadane’s Algorithm)

    link: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*

*/
int solveMaxSubSum(const vector<int> &arr)
{

    int max_sum = numeric_limits<int>::min();
    int max_end_here = 0;

    for (const int &i : arr)
    {
        max_end_here += i;

        // sum of all the element to the left of i is less than current
        // element which is negative. so the entire sum canceled by
        // setting max_end_here=0 becaus as it is negative adding it will
        // reduce the total sum.
        if (max_end_here <= 0)
        {
            max_end_here = 0;
            continue;
        }

        // if the entire sum is positive then adding it to total sum will
        // increase the total sum even if some element iin the sub array is negative.
        // so calculating the whether current total sum is greater than max_sum.
        max_sum = max(max_sum, max_end_here);
    }

    return max_sum;
}

int main()
{
    vector<int> arr{-1, 2, 3, 4, -2, 6, -8, 3};
    cout << solveMaxSubSum(arr);
}