//Soltuion to Largest Sum-Contagious Subaary problem of GFG
#include <bits/stdc++.h>
using namespace std;
int findLargestSumDP(vector<int> A, int n)
{
    //!! Dosent find the max for negative numbers
    //maxEndingHere stores the maximumum sum that ends at an index i.
    int maxEndingHere = 0, maxSoFar = 0;
    for (int i = 0; i < n; i++)
    {
        maxEndingHere += A[i];
        if (maxEndingHere < 0) //remove this conditon to accomadate negative values
            maxEndingHere = 0;
        else
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