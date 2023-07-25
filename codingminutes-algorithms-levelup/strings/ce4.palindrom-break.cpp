/*
Problem statement:
    Given a palindromic string of lowercase English letters palindrome,
    replace exactly one character with any lowercase English letter so
    that the resulting string is not a palindrome and that it is the
    lexicographically smallest one possible.

    Return the resulting string. If there is no way to replace a character
    to make it not a palindrome, return an empty string.

    leetcode: https://leetcode.com/problems/break-a-palindrome/
*/

#include <iostream>
#include <string>

using namespace std;

string breakPalindrome(string palindrome)
{
    int n = palindrome.size();
    if (n <= 1)
        return "";

    for (int i = 0; i < n / 2; i++)
    {
        // if any element is other than 'a' from the beginning is found, then
        // changing that to 'a' will automatically break the palindrome and
        // will also be lexicographically smaller.
        if (palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    // if answer is not found in the above loop means all the elements
    // in the array is 'a' so changing the last element to the next big char
    // will break the palindrome and also be the smallest.
    palindrome[n - 1] = 'b';
    return palindrome;
}

int main()
{
    string testCase = "abccba";
    // string testCase = "a";
    // string testCase = "aa";
    // string testCase = "aba";

    cout << "'" << breakPalindrome(testCase) << "'";
}