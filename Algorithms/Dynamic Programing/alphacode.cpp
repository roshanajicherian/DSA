#include <bits/stdc++.h>
using namespace std;
void solve(string S)
{
    int n = S.length();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        int x = S[i - 1] - '0';
        int y = S[i - 2] - '0';
        if (y == 1 || (y == 2 && x <= 6))
            dp[i] += dp[i - 2];
        if (x != 0)
            dp[i] += dp[i - 1];
    }
    cout << dp[n] << '\n';
}
int main()
{
    string S;
    cin >> S;
    while (S[0] != '0')
    {
        solve(S);
        cin >> S;
    }
    return 0;
}