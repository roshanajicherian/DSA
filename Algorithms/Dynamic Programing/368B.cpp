#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, m = 0;
    cin >> n >> m;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    set<lli> distinctSet;
    vector<lli> count(n, 0);
    count[n - 1] = 0;
    distinctSet.insert(A[n - 1]);
    for (lli i = n - 2; i >= 0; i--)
    {
        if (distinctSet.find(A[i]) == distinctSet.end())
        {
            distinctSet.insert(A[i]);
            count[i] = count[i + 1];
        }
        else
            count[i] = count[i + 1] + 1;
    }
    while (m--)
    {
        lli l = 0;
        cin >> l;
        l--;
        cout << (n - l) - (count[l]) << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}