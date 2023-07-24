/*
Problem statement:
    Write a function to perform basic string compression using the
    counts of repeated characters, also known as Run Length Encoding.
    Let see one example, the input string "aaaabcccccaaa" would become
    "a4b1c5a3". If the "compressed" string would not become smaller
    than the original string, your function should return the input
    string. You can assume the string has only uppercase and lowercase
    letters. You may use the to_string(int) method to convert an integer
    into string.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string runLengthEncode(const string &str)
{
    if (str.size() == 0)
        return "";

    vector<pair<char, int>> charFrequency;

    char check = str[0];
    int count = 1;
    bool moreThanOne = false;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == check)
        {
            count++;
            continue;
        }

        if (count > 1)
            moreThanOne = true;
        charFrequency.emplace_back(pair<char, int>{check, count});
        check = str[i];
        count = 1;
    }

    charFrequency.emplace_back(pair<char, int>{check, count});

    string encode = "";
    for (const pair<char, int> &p : charFrequency)
    {
        if (moreThanOne)
        {
            encode += (p.first + to_string(p.second));
            continue;
        }

        encode += p.first;
    }

    return encode;
}

int main()
{
    // string testCase = "bbbaaaadexxxxxx";
    // string testCase = "abc";
    string testCase = "";

    cout << runLengthEncode(testCase);
}