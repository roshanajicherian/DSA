#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1000
long long int factorial[MAXN + 1];
long long int fastPower(long long int base, long long int exponent)
{
    base = base % MOD;
    if (base == 0)
        return 1;
    long long int result = 1;
    while (exponent)
    {
        if (exponent & 1)
            result = (result * base) % MOD;
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}
long long int inverse(long long int x)
{
    return fastPower(x, MOD - 2);
}
void init()
{
    factorial[0] = factorial[1] = 1;
    for (long long int i = 2; i <= MAXN; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}
long long int solve(long long int n, long long int r)
{
    //nCr=n!/(n-r)!(r)!
    return ((factorial[n] * inverse(factorial[n - r])) % MOD * (inverse(factorial[r])) % MOD) % MOD;
}
int main()
{
    init();
    long long int n = 0, r = 0;
    cin >> n >> r;
    cout << solve(n, r) << '\n';
    return 0;
}