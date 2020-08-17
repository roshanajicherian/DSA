#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, d = 0;
    cin >> n >> d;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    lli count = 0;
    sort(A.begin(), A.end());
    for (lli i = 0; i < n; i++)
    {
        if (i + 2 < n)
        {
            for (lli j = i + 2; j < n; j++)
            {
                if (abs(A[j] - A[i]) <= d)
                    count += (j - i - 1);
            }
        }
    }
    cout << count << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}