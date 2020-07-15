#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int countOne = 0, currentMax = 0, maxSoFar = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 1)
            countOne++;
        int val = (A[i] == 1) ? -1 : 1;
        currentMax = max(val, currentMax + val);
        maxSoFar = max(maxSoFar, currentMax);
    }
    maxSoFar = max(0, maxSoFar);
    cout << maxSoFar + countOne << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}