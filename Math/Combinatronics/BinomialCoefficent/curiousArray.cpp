//Soltion to Curious Array of CodeForces
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1001
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
int binomialCoefficent(int n, int r)
{
    int ans = factorial[n];
    ans = (ans * inverse(factorial[n - r])) % MOD;
    ans = (ans * inverse(factorial[r])) % MOD;
    return ans;
}
void solve()
{
    //n=No. of elements in the array
    //m=No of queries
    int n = 0, m = 0;
    cin >> n >> m;
    int A[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
    {
        //l=Left limit
        //r=right limit
        //k=element to be used in the formula
        int l = 0, r = 0, k = 0;
        cin >> l >> r >> k;
        for (int j = l; j <= r; j++)
            A[j] = (A[j] % MOD + binomialCoefficent(j - l + k, k) % MOD) % MOD;
    }
    for (int i = 1; i <= n; i++)
        cout << A[i] << ' ';
    cout << '\n';
}
int main()
{
    init();
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}