/*
Problem Statement:
    given a array of distinct integers, find the length of the highest mountain.

        - A mountain is defined as adjacent integer that are strictly increasing
          until they reach a peak, at which they become strictly decreasing.

        - At least 3 numbers are required to form a mountain.

        - a number sequence with only pick and no descend is not a mountain.
*/

#include <iostream>
#include <vector>

using namespace std;

int solveMountain(const vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return 0;

    int maxMountain = 0;
    int tempCont = 0;

    // upwardSlope and downwardSlope is required because there can be a scenario where
    // all the elements in the array is decreasing. so we have to check whether we are
    // climbing down the mountain only after climbing up.
    bool upwardSlope = false;
    bool downwardSlope = false;

    // running the loop till n so we can calculate slope downward or upward till last element.
    // doing the loop from 0 to (n-1) cause the problem when we have to check whether the last
    // element is included in the slope or not.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            // while moving up if downwardSlope is true that means previously we
            // were going down the mountain but now we have reached lower junction
            // from where we are climbing the next mountain. so setting the
            // downwardSlope to false because it will be again set when we will be climbing down.
            // we are not calculating the max here because that already got calculated when we
            // were climbing down the slope with each iterate.
            if (downwardSlope)
            {
                downwardSlope = false;
                // this should be set to 1 because (i-1) element is also included in the new
                // mountain that is going to be calculated after this but setting it to zero because
                // outside this if condition it being set to 1;
                tempCont = 0;
            }
            upwardSlope = true;
            tempCont++;
        }
        else if (arr[i] < arr[i - 1])
        {
            // while moving down the mountain if previously we were climbing
            // it then check if current count is max and change it globally. we are
            // calculating max with each downward iteration because if the loop ends we
            // don't have to worry about whether the last element is counted in the max or not.
            // we are not settting temp count to zero berceuse that will be done when we
            // will climb the mountain again.
            if (upwardSlope)
            {
                // oly setting downwardSlope to true if we had previously climbed the mountain
                // because a montane with only down slope is not counted.
                downwardSlope = true;
                tempCont++;
                maxMountain = max(maxMountain, tempCont + 1);
            }
        }
        // reset entire count if consecutive two elements are same
        // so from next element we can start climbing the mountain again
        else if (arr[i] == arr[i - 1])
        {
            tempCont = 0;
            upwardSlope = false;
            downwardSlope = false;
        }
    }

    // if the last element was part o the downward slope then it should have already been added into max
    // while climbing down the mountain but if it was part of upward slope then it need not to be calculated.
    // thats why we need not to be worried about last element.

    return maxMountain;
}

int main()
{

    vector<vector<int>> testCases{
        {3, 3, 3},
        {3, 4, 5},
        {3, 2, 1},
        {3, 8, 2},
        {0, 1, 0, 1},
        {2, 3, 3, 2, 0, 2},
        {0, 2, 0, 2, 1, 2, 3, 4, 4, 1},
        {0, 2, 0, 2, 1, 2, 3, 4, 4, 4, 1},
        {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4},
        {5, 6, 1, 2, 3, -2, 4, 1, 2, 3, 4, 5, 4, 3, 2, 0},
        {5, 6, 1, 2, 3, -2, 4, 1, 2, 3, 4, 5, 4, 3, 2, 9},
        {1, 2, 3, 4, 5, 4, 3, 2, 0, 5, 6, 1, 2, 3, -2, 4},
    };
    vector<int> results{0, 0, 0, 3, 3, 0, 3, 3, 9, 9, 8, 9};

    for (int t = 0; t < testCases.size(); t++)
    {
        int solve = solveMountain(testCases[t]);
        cout << results[t] << " - " << solve;
        if (solve == results[t])
            cout << " - PASS";
        else
        {
            cout << " - FAILED -- { ";
            for (const int &i : testCases[t])
                cout << i << ", ";
            cout << "}";
        }

        cout << endl;
    }
}