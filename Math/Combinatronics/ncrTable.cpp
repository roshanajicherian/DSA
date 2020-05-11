#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define MOD 1000000000
typedef long long int lli;
int Pascal[MAXN + 1][MAXN + 1];
void PascalTriangleCompute()
{
    Pascal[0][0] = 1;
    for (int i = 0; i <= MAXN; i++)
    {
        Pascal[i][0] = Pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            Pascal[i][j] = (Pascal[i - 1][j - 1] + Pascal[i - 1][j]) % MOD;
    }
}
void solve()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cout << Pascal[n][i] << ' ';
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PascalTriangleCompute();
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}