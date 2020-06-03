#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    vector<lli> timeArray(n + 1);
    timeArray[1] = 5;
    for (lli i = 2; i <= n; i++)
        timeArray[i] = timeArray[i - 1] + (5 * i);
    lli low = 1, high = n;
    lli result = 0;
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        if (timeArray[mid] + k <= 240)
        {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << '\n';
}
int main()
{
    solve();
    return 0;
}