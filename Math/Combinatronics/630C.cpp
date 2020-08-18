#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    int n = 0;
    cin >> n;
    lli ans = (lli(2) << n) - 2;
    cout << ans << '\n';
}
int main()
{

    solve();
    return 0;
}