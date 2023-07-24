/*
Problem statement:
    You are given a vector of numbers. You want to concatenate these
    numbers together to form the lexicographically largest number.
    Print that largest number number. You can't rearrange the digits
    of any number, however you can place the numbers next to each other
    in any order.

    leetcode: https://leetcode.com/problems/largest-number/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// lexicographic comparision of two same length number is always follows
// the same behaviour as numeric comparision.
bool comparator(const int &first, const int &second)
{
    return to_string(first) + to_string(second) > to_string(second) + to_string(first);
}

string concatenate(vector<int> numbers)
{
    const int n = numbers.size();

    sort(numbers.begin(), numbers.end(), comparator);

    string result = "";
    for (const int &i : numbers)
    {
        result += to_string(i);
    }

    // only if all the element in the array is zero then only zero will be
    // the first element in the result. so rather returning all zero just
    // returning single zero.
    if (result[0] == '0')
        return "0";

    return result;
}

int main()
{
    // vector<int> testCase{10, 11, 20, 30, 3};
    // vector<int> testCase{3, 30, 34, 5, 9};
    // vector<int> testCase{0, 0, 0, 0, 0};
    vector<int> testCase{0, 0, 0, 1, 0};
    cout << concatenate(testCase);
}