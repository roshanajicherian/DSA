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
    lli maxSum = 0;
    set<lli> subsequence;
    lli i = 0;
    while (i < n)
    {
        if (A[i] < 0)
        {
            while (A[i] < 0 && i < n)
            {
                subsequence.insert(A[i]);
                i++;
            }
                }
        else
        {
            while (A[i] > 0 && i < n)
            {
                subsequence.insert(A[i]);
                i++;
            }
        }
        maxSum += *subsequence.rbegin();
        subsequence.clear();
    }
    cout << maxSum << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}