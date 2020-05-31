//soltion to EKO on SPOJ
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool isFeasible(vector<lli> A, lli height, lli m)
{
    lli sum = 0;
    for (auto i : A)
    {
        if (i > height)
            sum += (i - height);
        if (sum >= m)
            return true;
    }
    return false;
}
void solve()
{
    lli n = 0, m = 0;
    cin >> n >> m;
    vector<lli> A(n);
    lli maxElement = INT_MIN;
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        maxElement = max(maxElement, A[i]);
    }

    lli low = 0, high = maxElement;
    lli res = INT_MIN;
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        if (isFeasible(A, mid, m))
        {
            low = mid + 1;
            res = max(res, mid);
        }
        else
            high = mid - 1;
    }
    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}