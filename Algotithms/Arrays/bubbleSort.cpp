#include <stdio.h>
#include <iostream>
using namespace std;

int recursiveRubbleSort(int arr[], int n)
{

    if (n == 0 || n == 1)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
    recursiveRubbleSort(arr, n - 1);
}

int normalBubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}
int main()
{
    int arr[6];
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    normalBubbleSort(arr, n);

    return 0;
}
