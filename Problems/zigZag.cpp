// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1?page=1&curated[]=1&sortBy=submissions

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n)
    {
        bool relation = true;
        // code here
        for (int i = 0; i < n - 1; i++)
        {
            if (relation)
            {
                if (arr[i] > arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
                relation = false;
            }
            else
            {
                if (arr[i] < arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
                relation = true;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    ob.zigZag(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

// } Driver Code Ends