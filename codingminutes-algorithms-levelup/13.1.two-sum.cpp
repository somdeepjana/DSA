/*
Problem Statement:

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solve(vector<int> &input, int sum)
{
    unordered_set<int> memory;

    for (const auto &i : input)
    {
        if (memory.find(i) == memory.end())
        {
            return {i, sum - i};
        }

        memory.emplace(sum - i);
    }

    return {0, 0};
}

int main()
{
    int sum = 4;
    vector<int> input = {10, 5, 2, 3, -6, 9, 11};
    for (const int &a : solve(input, sum))
    {
        cout << a << " ";
    }
}