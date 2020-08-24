#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, d = 0;
    cin >> n >> d;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        lli elementGreater = upper_bound(A.begin(), A.end(), A[i] + d) - A.begin();
        lli numberOfElements = elementGreater - i - 1;
        if (numberOfElements > 1)
            ans += ((numberOfElements) * (numberOfElements - 1)) / 2;
    }
    cout << ans << '\n';
}
int main()
{
    solve();
    return 0;
}