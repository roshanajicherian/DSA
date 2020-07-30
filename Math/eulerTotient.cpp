#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    lli res = n;
    for (lli i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res *= (i - 1);
            res /= i;
        }
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
    {
        res *= (n - 1);
        res /= n;
    }
    cout << res << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}