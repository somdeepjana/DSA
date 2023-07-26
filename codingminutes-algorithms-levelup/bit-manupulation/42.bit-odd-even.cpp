/*
Problem statement:
    Write a function to determine a number is odd or even by their bit value
*/

#include <iostream>

using namespace std;

// if last bit(LSB) of a number is 1 then number is odd
string solveBit(int numb)
{
    // last bit will be returned as it is other bit will be covered with 0
    int lastBit = numb & 1;

    if (lastBit == 1)
        return "Odd";

    return "Even";
}

int main()
{
    int testCase = 0b01010;
    // int testCase = 0b00111;

    cout << "Number: " << testCase << ", " << solveBit(testCase);
}