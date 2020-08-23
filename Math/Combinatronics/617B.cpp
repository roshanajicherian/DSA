#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, countOnes = 0;
    cin >> n;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i])
            countOnes++;
    }
    if (countOnes == 1 || countOnes == 0)
    {
        cout << countOnes << '\n';
        return;
    }
    lli i = 0, ans = 1;
    lli start = -1, end = -1;
    while (i < n)
    {
        if (A[i] == 1 && start == -1)
            start = i;
        else if (A[i] == 1 && start != -1 && end == -1)
        {
            end = i;
            if (end - start != 1)
                ans *= (end - start);
            start = i;
            end = -1;
        }
        i++;
    }
    cout << ans << '\n';
}
int main()
{
    solve();
    return 0;
}