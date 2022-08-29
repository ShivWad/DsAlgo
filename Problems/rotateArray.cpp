// https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1?page=1&category[]=Arrays&curated[]=8&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// #include <algorithm>

// } Driver Code Ends
class Solution
{
public:
    /**
     *
     * @param arr input array
     * @param n: size of array
     * @param rotateBy: rotate array by this much
     * @brief     Function to rotate array by specified amount.

    */
    void rotateArray(int arr[], int n, int rotateBy)
    {
        // Your code here ;
            // n=5;
        rotateBy%=n;


    
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            if (i < rotateBy)
            {
                temp = arr[n - rotateBy + i];
                arr[n - rotateBy + i] = arr[i];
            }
            else if (i >= rotateBy)
            {
                arr[i - rotateBy] = arr[i];
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n;
    int r;
    cin >> n; // input size of array
    cin >> r;
    int a[n]; // declare vector of size n
    for (int i = 0; i < n; i++)
        cin >> a[i]; // input elements of array
    Solution ob;
    ob.rotateArray(a, n, r);

    for (int i = 0; i < n; i++)
        cout << a[i] << " "; // print array

    cout << endl;
}
// } Driver Code Ends

// void rotateArray(int arr[], int n, int rotateBy)
// {
//     // Your code here

//     if (rotateBy == n)
//         return;

//     while (rotateBy)
//     {
//         int firstEle = arr[0];
//         for (int i = 0; i < n; i++)
//         {
//             int temp = arr[i];
//             arr[i] = arr[i + 1];
//             arr[i + 1] = temp;
//         }
//         arr[n - 1] = firstEle;
//         rotateBy--;
//     }
// }