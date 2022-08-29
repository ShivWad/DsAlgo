#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;

void searchElem(int arr[], int n)
{

    int maxEle = INT_MIN;
    int minEle = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (maxEle < arr[i])
            maxEle = arr[i];

        if (minEle > arr[i])
            minEle = arr[i];
    }

    cout << maxEle << "     " << minEle;
}

int main()
{
    int arr[7] = {4, 7, -3, -1, 65, 13, 6};
    int n = 7;
    searchElem(arr, n);
    return 0;
}
