/*
Problem Statement:
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    leetcode: https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>

using namespace std;

// basic optimized solution
int solveRain(const vector<int> &height)
{
    int result = 0;
    vector<int> left(height.size());
    vector<int> right(height.size());
    int forwardMax = 0;
    int backwardMax = 0;

    /*
        say i is anywhere in the height array to calculate the max element
        to the right of the array from i and max element to the left of the
        array form i we are creating two arrays. so at any index of i left array
        will contain all the max element present to the let of i.
    */
    for (int i = 0; i < height.size(); i++)
    {
        forwardMax = max(forwardMax, height[i]);
        left[i] = forwardMax;

        backwardMax = max(backwardMax, height[height.size() - i - 1]);
        right[height.size() - i - 1] = backwardMax;
    }

    /*
        for each element at i checking the max element to the right and max element
        to the left then taking the minimum of them because extra water will overflow.
        this minimum will give how much water can be stored on ith position. from this
        subtracting ith bar height because that area will not have water.
    */
    for (int i = 0; i < height.size(); i++)
    {
        result += min(left[i], right[i]) - height[i];
    }

    return result;
}

/*
    better optimized solution with less space

    we are selecting the left end bar and right end bar and
    completely forgetting about all the bars in the middle. then
    calculating how much water can be stored between these two by
    getting the min bar height and subtracting the min bar hight from
    it. for first iteration this will select out of those two end bar
    which bar will not have any water on top of it. so after this
    either increasing the left pointer or reducing right pointer by one
    based on whichever have min vale.

    Then next iteration we are checking bar heigh in the right
    and bar height in the left which have new pointer based on previous
    operation. then checking which ever have low bar height that will
    have the water on top of it. then checking what is the min value between
    (max vale so far rom right) and (max vale from left) because minimum of
    these two amount of water can be present on top of current index. then
    negating the current index bar height from it so that we will be getting
    water left.
*/
int lessSpaceSol(const vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;

    int leftMax = height[l];
    int rightMax = height[r];

    int result = 0;

    while (l < r)
    {
        // left and right max so far
        leftMax = max(leftMax, height[l]);
        rightMax = max(rightMax, height[r]);

        // minimum off these will be storing on the current bar.
        int minBar = min(leftMax, rightMax);

        // left or right whichever have low height will be included
        // in the water calculation counting the other one will only
        // be included when any bar greater than it is fond later.
        if (height[l] < height[r])
        {
            result += minBar - height[l];
            l++;
            continue;
        }

        result += minBar - height[r];
        r--;
    }

    return result;
}

int main()
{
    vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << lessSpaceSol(heights);
}