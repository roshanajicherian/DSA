#include <bits/stdc++.h>
using namespace std;
int findMinimumSquares(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = i;
        for (int x = 1; x * x <= i; x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    return dp[n];
}
int main()
{
    int n = 0;
    cin >> n;
    cout << findMinimumSquares(n) << '\n';
    return 0;
}