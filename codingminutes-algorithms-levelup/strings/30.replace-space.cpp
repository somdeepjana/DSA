/*
Problem Statement:
    Given a string, write a function to replace all spaces in a string with
    '%20'. It is given that the string has sufficient space at the end to hold
    te additional characters.
*/

#include <iostream>

using namespace std;

void solveSpace(string &str)
{
    int original_len = str.size() - 1;

    // resize te extra space
    int extra_space = 0;
    for (const char &c : str)
    {
        if (c == ' ')
            extra_space += 2; // 1 space is already there for '%' 2 extra is require for '2' and '0'
    }
    if (extra_space == 0)
        return;
    str.resize(original_len + extra_space + 1);

    int end = original_len + extra_space;
    while (original_len >= 0)
    {
        if (str[original_len] != ' ')
        {
            str[end--] = str[original_len--];
            continue;
        }

        str[end--] = '0';
        str[end--] = '2';
        str[end--] = '%';
        original_len--;
    }
}

int main()
{
    string testString = "hello world,  how are you?";
    solveSpace(testString);
    cout << testString << "|";
}