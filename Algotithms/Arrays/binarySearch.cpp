#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    // code here
    int s_ind = 0;
    int e_ind = n - 1;
    int m_ind;

    while (s_ind <= e_ind)
    {
        m_ind = (e_ind + s_ind) / 2;
        if (arr[m_ind] == k)
        {
            return m_ind;
        }
        else
        {
            if (arr[m_ind] > k)
            {
                e_ind = m_ind - 1;
            }

            else
            {
                s_ind = m_ind + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n = 5;
    int k = 4;
    int arr[5] = {1, 2, 3, 4, 5};
    int ans = binarysearch(arr, n, k);

    cout << ">>" << ans;
}