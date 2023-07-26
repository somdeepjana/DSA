/*
Problem statement:
    calculate a^n in O(long n) time complexity. usually it have O(n)
    time complexity. but in most of the languages int is a 32 bit integer
    so log n = 32 which is a constant so time complexity will 0(1).
*/

#include <iostream>

/*
    so for 3^5
    we can write 5-> 0b101
    so 3^(0b101)

    if we convert 0b101 to 1x2^2 + 0x2^1 + 1x2^0
    now we get 3^(1x2^2 + 0x2^1 + 1x2^0) = 3^(1x2^2) * 3^(0x2^1) * 3^(1x2^0)
    so solving it we get
    3^4 * 3^0 * 3^1
    3^(2+2) * 1 * 3^(1)
    so excluding 0 bit we get a series like this
    (3*3*3*3) * (3*3) * (3)
    so for each bit of exponent value of 3 getting double of previous one
    so for 15 the series is like this (3^(2+2+2) * 3^(2+2) * 3^(2) * 3^(1))
    which will be like (3*3*3*3*3*3) * (3*3*3*3) * (3*3) * 3
*/
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
    int exponent = 5;

    cout << fastExponent(numb, exponent);
}