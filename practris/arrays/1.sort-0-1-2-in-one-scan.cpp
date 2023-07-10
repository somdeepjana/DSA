/*
Problem Statement:
    Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

    link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int zeroPoint = 0;
        int onePoint = 0;
        int twoPoint = n - 1;

        while (onePoint <= twoPoint)
        {
            switch (a[onePoint])
            {
            case 0:
                swap(a[onePoint++], a[zeroPoint++]);
                break;
            case 1:
                onePoint++;
                break;
            case 2:
                swap(a[onePoint], a[twoPoint--]);
                break;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
