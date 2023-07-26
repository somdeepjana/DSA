/*
Problem Statement:
    given number count the number of set bits
*/

#include <iostream>

using namespace std;

int countSetBit(int num)
{
    int count = 0;
    while (num > 0)
    {
        int one = num & 1;

        if (one == 1)
            count++;

        num = num >> 1;
    }

    return count;
}

int main()
{
    int numb = 0b001011101;

    cout << countSetBit(numb);
}