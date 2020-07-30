#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli a = 0, b = 0;
    cin >> a >> b;
    cout << min(a, min(b, (a + b) / 3)) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}