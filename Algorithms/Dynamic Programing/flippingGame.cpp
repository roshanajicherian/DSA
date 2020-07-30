#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    lli countOne = 0, currentMax = 0, maxSoFar = 0;
    for (lli i = 0; i < n; i++)
    {
        if (A[i] == 1)
            countOne++;
        lli val = (A[i] == 1) ? -1 : 1;
        currentMax = max(val, currentMax + val);
        maxSoFar = max(maxSoFar, currentMax);
    }
    maxSoFar = max((lli)0, maxSoFar);
    cout << maxSoFar + countOne << '\n';
}
int main()
{
    solve();
    return 0;
}