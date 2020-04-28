//soultion to NWAYS problem of Codechef
#include <bits/stdc++.h>
typedef long long int lli;
#define MAXN 1000
#define MOD 1000000007
lli factorial[MAXN];
using namespace std;
void init()
{
    factorial[0] = factorial[1] = 1;
    for (lli i = 2; i < MAXN; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}
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
lli inverse(lli x)
{
    return fastPower(x, MOD - 2);
}
lli binomialCoefficent(lli n, lli r)
{
    return ((factorial[n] * inverse(factorial[n - r])) % MOD * (inverse(factorial[r])) % MOD) % MOD;
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
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