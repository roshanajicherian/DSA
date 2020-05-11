#include <bits/stdc++.h>
using namespace std;
#define MAXN 250
#define MOD 1000000007
typedef long long int lli;
lli factorial[MAXN];
lli fastPower(lli base, lli exponent)
{
    base = base % MOD;
    if (base == 0)
        return 1;
    lli result = 1;
    while (exponent)
    {
        if (exponent & 1)
            result = (result * base) % MOD;
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}
lli inverse(lli a)
{
    return fastPower(a, MOD - 2);
}
lli binomialCoefficent(lli n, lli r)
{
    lli ans = ((factorial[n] * inverse(factorial[n - r])) % MOD * (inverse(factorial[r])) % MOD) % MOD;
    return ans;
}
void solve()
{
    lli n = 0, m = 0;
    cin >> n >> m;
    lli ans = binomialCoefficent(n+m, m);
    cout << ans << '\n';
}
void init()
{
    factorial[0] = factorial[1] = 1;
    for (lli i = 2; i < MAXN; i++)
        factorial[i] = (i * factorial[i - 1]) % MOD;
}
int main()
{
    init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}