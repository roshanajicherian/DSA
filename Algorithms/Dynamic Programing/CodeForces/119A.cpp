#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, a = 0, b = 0, c = 0;
    cin >> n >> a >> b >> c;
    int DP[n + 1];
    fill(DP, DP + n + 1, INT_MIN);
    DP[0] = 0;
    for (int i = a; i <= n; i++)
        DP[i] = max(DP[i], DP[i - a] + 1);
    for (int i = b; i <= n; i++)
        DP[i] = max(DP[i], DP[i - b] + 1);
    for (int i = c; i <= n; i++)
        DP[i] = max(DP[i], DP[i - c] + 1);
    cout << DP[n] << '\n';
}
int main()
{
    solve();
    return 0;
}