#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int arr[6];
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                int temp = min;
                min = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = min;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}