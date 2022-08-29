#include <iostream>
using namespace std;

void swap(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    swap(arr, start + 1, end - 1);
}

int main()
{
    int arr[7] = {4, 2, 3, 9, 5, 8, 0};
    int n = 7;

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    swap(arr, 0, n - 1);

    cout << endl;

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}