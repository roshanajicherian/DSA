#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    if (lower_bound(A.begin(), A.end(), x) == A.end() || *lower_bound(A.begin(), A.end(), x) != x)
    {
        cout << -1 << '\n';
        return;
    }
    int start = 0, end = 0;
    start = lower_bound(A.begin(), A.end(), x) - A.begin();
    if (upper_bound(A.begin(), A.end(), x) == A.end())
        end = n - 1;
    else
        end = start + upper_bound(A.begin(), A.end(), x) - lower_bound(A.begin(), A.end(), x) - 1;
    cout << start << ' ' << end << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}