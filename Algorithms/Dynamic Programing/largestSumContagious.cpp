//Soltuion to Largest Sum-Contagious Subaary problem of GFG
//The soltuion uses Kadane's Algorithm to find the largest Sum Contigious Subarray
#include <bits/stdc++.h>
using namespace std;
int findLargestSumDP(vector<int> A, int n)
{
    int maxEndingHere = A[0], maxSoFar = A[0];
    for (int i = 1; i < n; i++)
    {
        maxEndingHere = max(A[i], maxEndingHere + A[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        A.push_back(temp);
    }
    cout << findLargestSumDP(A, n) << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}