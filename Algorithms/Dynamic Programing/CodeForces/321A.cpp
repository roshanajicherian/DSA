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
    vector<lli> DP(n, 1);
    for (lli i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
            DP[i] += DP[i - 1];
    }
    cout << *max_element(DP.begin(), DP.end()) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}