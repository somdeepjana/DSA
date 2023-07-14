/*
Problem Statement:
    check video https://edgeverve.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23915412#overview


*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> memory;

string getNum(string str, int column)
{

    if (memory.find(str) != memory.end())
        return memory[str];

    stringstream ss(str);
    string token;
    int idx = 0;
    while (getline(ss, token, ' '))
    {
        idx++;
        if (idx == column)
            break;
    }

    memory[str] = token;
    return token;
}

auto stringComparator(int column, bool numeric, bool rev)
{
    return [column, numeric, rev](const string &first, const string &second) -> bool
    {
        string firstNum = getNum(first, column);
        string secondNum = getNum(second, column);

        if (numeric)
        {
            int num1 = stoi(firstNum);
            int num2 = stoi(secondNum);

            if (rev)
            {
                return num1 > num2;
            }

            return num1 < num2;
        }

        if (rev)
        {
            return firstNum > secondNum;
        }

        return firstNum < secondNum;
    };
}

int main()
{
    vector<string> strs{
        "92 022", "82 12", "77 13"};

    sort(strs.begin(), strs.end(), stringComparator(2, true, false));

    for (const string &i : strs)
    {
        cout << i << endl;
    }
}