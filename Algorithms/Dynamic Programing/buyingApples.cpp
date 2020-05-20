//solution to Buying Apples Problem on SPOJ
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int price[k + 1];
    for (int i = 1; i <= k; i++)
        cin >> price[i];
    int ans[k + 1];
    for (int i = 1; i <= k; i++)
        ans[i] = price[i];
    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (price[i - j] == -1 || ans[j] == -1)
                continue;
            if (ans[i] == -1)
                ans[i] = price[i - j] + ans[j];
            else
                ans[i] = min(ans[i], price[i - j] + ans[j]);
        }
    }
    cout << ans[k] << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}