#include <stdio.h>
#include <iostream>
using namespace std;

bool searchElem(int arr[], int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (ele == arr[i])
            return 1;
    }

    return 0;
}

int main()
{
    int arr[7] = {4, 7, -3, -1, 65, 13, 6};
    int n = 7;
    bool anser = searchElem(arr, n, 1);
    cout << anser;
    return 0;
}
