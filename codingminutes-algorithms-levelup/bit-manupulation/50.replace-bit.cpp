/*
Problem statement:
    You are given two 32 bit numbers M and N and two bit position i ans j.
    Write a method to set all the bits between i and j in N so tha all
    bits between i and j become similar to M.
*/

#include <iostream>
#include <bitset>

using namespace std;

void clearInRange(int &n, int i, int j)
{
    int msbSet = (~0) << (j + 1);
    int lsbSet = (1 << i) - 1;
    int clearSet = msbSet | lsbSet;

    n = n & clearSet;
}

void replaceBit(int &N, int M, int i, int j)
{
    clearInRange(N, i, j);

    // left shift M to i position.
    int mask = M << i;

    N = N | mask;
}

int main()
{
    int N = 0b10000000000;
    int M = 0b10101;
    int i = 2, j = 6;

    replaceBit(N, M, i, j);
    bitset<16> x(N);
    cout << x;
}