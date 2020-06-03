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
        int i = 0;
        while (i < n)
        {
            if (q <= prefixSum[i])
                break;
            i++;
        }
        cout << i+1 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}