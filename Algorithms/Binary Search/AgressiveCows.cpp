#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool isFeasible(vector<lli> A, lli n, lli c, lli minimumDistance)
{
    lli prev = A[0];
    lli res = 1;
    for (lli i = 0; i < n; i++)
    {
        if (A[i] - prev >= minimumDistance)
        {
            res++;
            prev = A[i];
            if (res == c)
                return true;
        }
    }
    return false;
}
lli BinarySeach(vector<lli> A, lli c)
{
    lli n = A.size();
    lli maximumDistance = INT_MIN;
    lli low = A[0], high = A[n - 1];
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        if (isFeasible(A, n, c, mid))
        {
            maximumDistance = max(maximumDistance, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return maximumDistance;
}
void solve()
{
    lli n = 0, c = 0;
    cin >> n >> c;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    lli result = BinarySeach(A, c);
    cout << result << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;

    while (t--)
        solve();
    return 0;
}