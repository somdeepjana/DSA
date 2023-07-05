/*
Problem statement:
    Given a unsorted array find minimum number or swaps required to
    sort the array.

*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solveMinSwap(const vector<int> &arr)
{
    int n = arr.size();
    int result = 0;
    bool *visited = new bool[n];

    // storing the previous index of the element that will be required
    // while calculating the swap.
    pair<int, int> *ap = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;

        visited[i] = false;
    }

    // sorting the array element(pair sort based on pair.first element)
    // to know where each element should originally go.
    sort(ap, ap + n);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true || ap[i].second == i)
            continue;

        // if the element is not visited then checking what was the previous
        // index of the current element. then going to that index in sorted array
        // and checking what was the previous index off that element. doing this
        // until we are back at the first index we started with. this will give
        // the number of element present in the cycle.
        int cycleNodes = 0;
        int node = i;
        while (visited[node] == false)
        {
            cycleNodes++;
            visited[node] = true;
            node = ap[node].second;
        }

        // n element in a cycle can do (n-1) number of swaps.
        result += cycleNodes - 1;
    }

    return result;
}

int main()
{
    // vector<int> arr{5, 4, 3, 2, 1};
    vector<int> arr{2, 4, 5, 1, 3};
    // vector<int> arr{1, 5, 4, 3, 2};

    cout << solveMinSwap(arr);
}