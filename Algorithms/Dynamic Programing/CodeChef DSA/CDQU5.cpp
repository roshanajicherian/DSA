#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD 1000000009
#define MAXN 1000000
vector<lli> dp(MAXN + 1);
void init()
{
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for (lli i = 4; i <= MAXN; i++)
        //DP recurence relation
        dp[i] = (dp[i - 2] % MOD + dp[i - 3] % MOD) % MOD;
}
void solve()
{
    lli x = 0;
    cin >> x;
    cout << dp[x] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}