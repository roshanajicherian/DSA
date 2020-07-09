#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli findCumilative(vector<lli> A)
{
    lli n = A.size();
    lli maxSum = 0, windowSum = 0;
    for (lli i = 0; i < 3; i++)
        maxSum += A[i];
    windowSum = maxSum;
    for (lli i = 3; i < n; i++)
    {
        windowSum = windowSum + A[i] - A[i - 3];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    cout << findCumilative(A) << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}