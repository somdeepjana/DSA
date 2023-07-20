/*
Problem Statement:
    given a string you need to print all subsequences of that string sorted
    by length and lexicographic sorted order if length is same


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customComparator(const string &first, const string &second)
{
    if (first.size() == second.size())
    {
        return first < second;
    }

    return first.size() < second.size();
}

void subsequence(string str, string out, vector<string> &result)
{
    if (str.size() == 0)
    {
        result.emplace_back(out);
        return;
    }

    char ch = str[0];
    string reduce_str = str.substr(1);
    subsequence(reduce_str, out + ch, result); // adding all the element with first element
    subsequence(reduce_str, out, result);      // adding all the element without first element
}

vector<string> solveProblem(const string &str)
{
    vector<string> result;

    string out = "";
    subsequence(str, out, result);
    result.erase(result.begin()); // first element is complete string so not subset
    sort(result.begin(), result.end(), customComparator);

    return result;
}

int main()
{
    string str = "abcd";

    for (const string &s : solveProblem(str))
    {
        cout << s << ", ";
    }
}