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
    sort(A.begin(), A.end());
    lli q = 0;
    cin >> q;
    while (q--)
    {
        lli m = 0, result = 0;
        cin >> m;
        if (m < A[0])
        {
            cout << 0 << '\n';
            continue;
        }
        if (m >= A[n - 1])
        {
            cout << n << '\n';
            continue;
        }
        lli low = 0, high = n - 1;
        while (low <= high)
        {
            lli mid = (low + high) / 2;
            if (m >= A[mid])
            {
                result = max(result, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << result + 1 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}