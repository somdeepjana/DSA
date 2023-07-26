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

// subtracting 1 from any number make all the 0 bit starting from LSB to
// first occurrence 1 to 1. means 0b00101000 -1 will be 0b00100111. and
// doing '&' operation with this number first occurrence of 1 from LSB.
// (0b0010 1 000) & (0b0010 0 111) = (0b0010 0000). so each iteration 1 gets
// remove until the whole number became 0.
int betterMethod(int num)
{
    int count = 0;

    while (num > 0)
    {
        num = num & (num - 1);
        count++;
    }

    return count;
}

int main()
{
    // int numb = 0b001011101;
    int numb = 0b00000010;

    cout << betterMethod(numb);
}