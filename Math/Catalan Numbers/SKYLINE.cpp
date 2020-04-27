#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MOD 1000000
int catlanDP[MAXN];
void init(int n)
{
    catlanDP[0] = catlanDP[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catlanDP[i] = 0;
        int res = 0;
        for (int j = 0; j < i; j++)
        {
            res = (catlanDP[j] % MOD * catlanDP[i - j - 1] % MOD) % MOD;
            catlanDP[i] = (catlanDP[i] % MOD + res) % MOD;
        }
    }
}
void solve(int n)
{
    cout << catlanDP[n] << '\n';
}
int main()
{
    init(1000);
    int t = 0;
    cin >> t;
    while (t != 0)
    {
        solve(t);
        cin >> t;
    }
}