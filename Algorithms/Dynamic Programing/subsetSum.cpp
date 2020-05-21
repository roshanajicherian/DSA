//Solution to subset sum problem of GFG
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, sum = 0;
    cin >> n >> sum;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    bool DP[n + 1][sum + 1];
    for (int i = 1; i <= sum; i++)
        DP[0][i] = false;
    for (int i = 0; i <= n; i++)
        DP[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - A[i - 1] < 0)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - A[i - 1]];
        }
    }
    if (DP[n][sum])
        cout << "True\n";
    else
        cout << "False\n";
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}