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
    lli maxResult = INT_MIN;
    for (lli i = 0; i < n; i++)
    {
        lli tempMax = A[i];
        if (i + 1 >= n)
            tempMax += A[(i + 1) % n];
        else
            tempMax += A[i + 1];
        if (i + 2 >= n)
            tempMax += A[(i + 2) % n];
        else
            tempMax += A[i + 2];
        maxResult = max(maxResult, tempMax);
    }
    cout << maxResult << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}