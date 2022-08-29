#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minInd = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minInd])
				minInd = j;
		}
		swap(arr[minInd], arr[i]);
	}
}

int main()
{
	int arr[] = {3, 1, 2, 4, 6};
	int n = 5;
	selectionSort(arr, n);

	for (auto x : arr)
		cout << x << " ";
	return 0;
}
