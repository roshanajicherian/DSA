#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD 1000000007
#define MAXN 2200000
lli factorial[MAXN + 1];
lli fastPower(lli base, lli exponent)
{
    lli result = 1;
    base = base % MOD;
    if (base == 0)
        return 1;
    while (exponent)
    {
        if (exponent & 1)
            result = (result % MOD * base % MOD) % MOD;
        exponent >>= 1;
        base = (base % MOD * base % MOD) % MOD;
    }
    return result;
}
lli inverse(lli x)
{
    return fastPower(x, MOD - 2);
}
void init()
{
    factorial[0] = factorial[1] = 1;
    for (lli i = 2; i < MAXN; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}
lli binomialCoeff(lli n, lli r)
{
    if (n < r)
        return 0;
    return ((factorial[n] * inverse(factorial[n - r])) % MOD * (inverse(factorial[r])) % MOD);
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    lli res = ((2LL * binomialCoeff(n + k + 1, k + 2)) % MOD - n + MOD) % MOD;
    //res = res % MOD;
    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    lli t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}