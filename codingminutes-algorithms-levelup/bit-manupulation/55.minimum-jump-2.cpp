/*
Problem statement:
    The Planet Earth is under a threat from the aliens of the outer
    space and your task is to defeat an enemy who is N steps above you
    (assume yourself to be at ground level i.e. at the 0th level).
    You can take jumps in power of 2. In order to defeat the enemy as
    quickly as possible you have to reach the Nth step in minimum moves
    possible.
*/

#include <iostream>
using namespace std;

/*
    7-> 0 1 1 1
    so only power of 2 can be possibles ar 0001, 0010, 0100.
    so counting the number of 1 will give the result
*/
int earthLevel(int k)
{
    // counting number of set bits
    int count = 0;
    while (k > 0)
    {
        count++;
        k = k & (k - 1); // removing left most set bit
    }

    return count;
}

int main()
{
    int testCase = 7;

    cout << earthLevel(testCase);
}