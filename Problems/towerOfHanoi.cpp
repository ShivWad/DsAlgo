// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
#include <bits/stdc++.h>

using namespace std;

long long toh(int N, int source, int to, int aux)
{
    // Your code here

    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << source << " to rod " << to << endl;
        return 1;
    }
    toh(N - 1, source, aux, to);
    cout << "move disk " << N << " from rod " << source << " to rod " << to << endl;
    toh(N - 1, aux, to, source);
    return pow(2, N) - 1;
}

int main()
{
    int n;
    cin >> n;  

    toh(n, 1, 3, 2);

    return 0;
}