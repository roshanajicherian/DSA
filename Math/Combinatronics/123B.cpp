#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    double ans = 0.0;
    while (n > 0)
    {
        ans += (1.0 / n);
        n--;
    }
    cout << fixed << setprecision(12) << ans << ' ';
}
int main()
{
    solve();
    return 0;
}