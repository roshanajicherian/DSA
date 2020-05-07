//Dynamic Programming solution to Maximum Increasing Subsequnce
#include <bits/stdc++.h>
using namespace std;
int MISDP(int A[], int n)
{
    //BOTTOM UP APPROACH
    //Lookup table to memoize the values
    int DP[n];
    //Base case: if a single element is the increasing subsequence
    for (int i = 0; i < n; i++)
        DP[i] = A[i];
    //Similar to LIS problem
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && DP[i] < DP[j] + A[i])
                DP[i] = DP[j] + A[i];
        }
    }
    //Finding out the max from all possible MIS
    int MISMax = 0;
    for (int i = 0; i < n; i++)
        MISMax = max(MISMax, DP[i]);
    return MISMax;
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << MISDP(A, n) << '\n';
    return 0;
}