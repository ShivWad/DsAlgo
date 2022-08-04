// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category[]=sliding-window&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i = 0;
        int j = 0;
        vector<int> ansVector;
        long long sum = 0;

        if (s == 0)
        {
            ansVector.push_back(-1);
            return ansVector;
        }

        while (j < n)
        {
            sum = sum + arr[j];
            while (sum > s)
            {
                sum = sum - arr[i];
                i++;
            }
            if (sum < s)
                j++;

            if (sum == s)
            {
                ansVector.push_back(i + 1);
                ansVector.push_back(j + 1);
                return ansVector;
            }
        }

        if (ansVector.empty())
        {
            ansVector.push_back(-1);
            return ansVector;
        }

        // Your code here
    }
};

//{ Driver Code Starts.

int main()
{

    int n;
    long long s;
    cin >> n >> s;
    int arr[n];
    const int mx = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    vector<int> res;
    res = ob.subarraySum(arr, n, s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
// } Driver Code Ends
