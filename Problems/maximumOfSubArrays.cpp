// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&category[]=Arrays&curated[]=8&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.

    // your code here
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here

        vector<int> ansArr;
        deque<int> tempDeque;
        int i = 0;
        int j = 0;

        while (j < n)
        {
            while (!tempDeque.empty() && tempDeque.back() < arr[j])
                tempDeque.pop_back();

            tempDeque.push_back(arr[j]);

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                ansArr.push_back(tempDeque.front());

                if (tempDeque.front() == arr[i])
                    tempDeque.pop_front();
                i++;
                j++;
            }
        }

        return ansArr;
    }
};

//{ Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    //  n size of array
    //  k size of sub array
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // for (int i = 0; i < n; i++)
    //     cout << arr[i];
    // cout << endl;

    Solution ob;
    vector<int> res = ob.max_of_subarrays(arr, n, k);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    cout << endl;

    return 0;
}

// vector<int> max_of_subarrays(int *arr, int n, int k)
// {

//     vector<int> tempArr;

//     for (int i = 0; i < n; i++)
//     {
//         if (i + k <= n)
//         {
//             int max = arr[i];

//             for (int j = i; j < i + k; j++)
//             {
//                 if (max < arr[j])
//                 {
//                     max = arr[j];
//                 }
//             }
//             tempArr.push_back(max);
//         }
//     }

//     return tempArr;
//     // your code here
// }