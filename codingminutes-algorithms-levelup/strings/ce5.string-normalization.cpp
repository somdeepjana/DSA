/*
Problem statement:
    You are given a sentence with words separated by spaces.

    Your task is to:

    Write a function that returns a copy of this sentence where all '
    the words:

        - start with a capital letter

        - the rest of the letters are lower case
*/

#include <iostream>

using namespace std;

string normalize(const string &sentence)
{
    string copy = sentence;
    // Make the changes in copy, and return it

    bool isSpaceBefore = true;

    for (char &c : copy)
    {
        if (c == ' ')
        {
            isSpaceBefore = true;
            continue;
        }

        if (isSpaceBefore)
        {
            c = toupper(c);
            isSpaceBefore = false;
            continue;
        }

        c = tolower(c);
    }

    return copy;
}

int main()
{
    // string testCase = "This is SO MUCH FUN!";
    // string testCase = "This is SO MUCH   FUN!";
    // string testCase = "abc";
    // string testCase = "a";
    // string testCase = "";
    // string testCase = " ";
    string testCase = "  abc  def ghi ";

    cout << "'" << normalize(testCase) << "'";
}