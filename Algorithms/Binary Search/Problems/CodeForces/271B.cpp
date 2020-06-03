#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    for (auto &i : A)
        cin >> i;
    vector<lli> prefixSum(n);
    prefixSum[0] = A[0];
    for (lli i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + A[i];
    lli m = 0;
    cin >> m;
    while (m--)
    {
        lli q = 0;
        cin >> q;
        cout << lower_bound(prefixSum.begin(), prefixSum.end(), q) - prefixSum.begin()+1<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}