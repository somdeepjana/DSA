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

bool comparator(const string &first, const string &second)
{
    const unsigned long long before = stoull(first + second);
    const unsigned long long after = stoull(second + first);

    return before > after;
}

string concatenate(vector<int> numbers)
{
    const int n = numbers.size();
    string *str_arr = new string[numbers.size()];

    for (int i = 0; i < n; i++)
    {
        str_arr[i] = to_string(numbers[i]);
    }

    sort(str_arr, str_arr + numbers.size(), comparator);

    string result = "";
    bool startWithZero = true;
    for (int i = 0; i < n; i++)
    {
        if (startWithZero && str_arr[i] == "0")
            continue;

        startWithZero = false;
        result += str_arr[i];
    }

    if (startWithZero)
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