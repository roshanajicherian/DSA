#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    if (n & 1 || n < 4)
    {
        cout << 0 << '\n';
        return;
    }
    double halfN = n / 2;
    cout << fixed << setprecision(0) << ceil((halfN - 2) / 2.0) << '\n';
}
int main()
{
    solve();
    return 0;
}