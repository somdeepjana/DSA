/*
Problem Statement:
    Given two strings s and t, return true if s is a subsequence of t,
    or false otherwise.

    A subsequence of a string is a new string that is formed from the
    original string by deleting some (can be none) of the characters
    without disturbing the relative positions of the remaining
    characters. (i.e., "ace" is a subsequence of "abcde" while "aec"
    is not).

    leetcode: https://leetcode.com/problems/is-subsequence/description/
*/

#include <iostream>

using namespace std;

bool isSubsequence(const string &s, const string &t)
{
    if (s.size() == 0)
        return true;
    int sPtr = 0;

    for (const char &c : t)
    {
        if (s[sPtr] == c)
        {
            sPtr++;
            if (sPtr == s.size())
                return true;
        }
    }
    return false;
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t))
        cout << "true";
    else
        cout << "false";
}