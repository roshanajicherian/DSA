//Program to find out the binomial coeffcient using DP
#include <bits/stdc++.h>
using namespace std;
int binomialCoeffDP(int n, int r)
{
    int dp[n + 1][r + 1]; //using 1 based indexing for simplicity
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}
int main()
{
    int n = 0, r = 0;
    cin >> n >> r;
    cout << binomialCoeffDP(n, r) << '\n';
    return 0;
}