//Codechef Problem PANSTACK as an example for Catlan Numbers
//Howver the solution is based on Bell Number
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MOD 1000000007
int bell[MAXN][MAXN];
void preComputeBellNumber(int n)
{

    bell[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bell[i][0] = bell[i - 1][i - 1];
        for (int j = 1; j <= i; j++)
            bell[i][j] = ((bell[i - 1][j - 1]) % MOD + (bell[i][j - 1]) % MOD) % MOD;
    }
}
void solve()
{
    int n = 0;
    cin >> n;
    cout << bell[n][0] << '\n';
}
int main()
{
    preComputeBellNumber(1000);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}