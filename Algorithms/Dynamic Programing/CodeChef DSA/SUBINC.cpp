#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    vector<lli> DP(n, 1);
    lli consecutiveCount = 0;
    for (lli i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
        {
            consecutiveCount++;
            DP[i] = DP[i - 1] + DP[i] + consecutiveCount;
        }
        else
        {
            consecutiveCount = 0;
            DP[i] = DP[i - 1] + DP[i];
        }
    }
    cout << DP[n - 1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}