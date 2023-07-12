/*
Problem Statement:
    Given the heights of N towers and a value of K, Either increase or
    decrease the height of every tower by K (only once) where K > 0.
    After modifications, the task is to minimize the difference between
    the heights of the longest and the shortest tower and output its
    difference. No tower with negative height possibe.

    GeekForGeeks: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
    Youtube: https://www.youtube.com/watch?v=o9WG7t6EKZo
*/

// C++ Code for the Approach

#include <bits/stdc++.h>
using namespace std;

// Difference betweens tower will be minimum when two consecutive
// elements difference is take in a sorted array.
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);

    // Maximum possible height difference
    int ans = arr[n - 1] - arr[0];

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++)
    {

        // If on subtracting k we got
        // negative then continue
        if (arr[i] < k)
            continue;

        // Minimum element when we
        // add k to whole array except first except we want to reduce differences
        tempmin = min(arr[0] + k, arr[i] - k);

        // Maximum element when we
        // subtract k from whole array except last because we want to reduce difference
        tempmax = max(arr[n - 1] - k, arr[i - 1] + k);

        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

// Driver Code Starts
int main()
{

    int k = 6, n = 6;
    int arr[n] = {7, 4, 8, 8, 8, 9};

    // Function Call
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}
