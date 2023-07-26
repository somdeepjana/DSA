/*
Problem statement:
    calculate a^n in O(long n) time complexity. usually it have O(n)
    time complexity. but in most of the languages int is a 32 bit integer
    so log n = 32 which is a constant so time complexity will 0(1).
*/

#include <iostream>

int fastExponent(int numb, int exponent)
{
    int result = 1;

    // calculate number of 1 in the exponent
    while (exponent > 0)
    {
        int one = exponent & 1;
        if (one == 1)
        {
            result *= numb;
        }

        // for each bit in exponent multiplying numb because
        // 0b0101 -> 0xnum^3 * 1xnum^2 * 0xnum^1 * 1xnum^0
        // so from above for each bit the num is getting multiplied by itself.
        // we are just ignoring the 0 multiplication to the result.
        numb = numb * numb;

        exponent = exponent >> 1;
    }

    return result;
}

using namespace std;

int main()
{
    int numb = 3;
    int exponent = 4;

    cout << fastExponent(numb, exponent);
}