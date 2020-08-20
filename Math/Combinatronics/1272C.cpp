#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    string S;
    cin >> S;
    set<char> avilableKeys;
    while (k--)
    {
        char temp;
        cin >> temp;
        avilableKeys.insert(temp);
    }
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        lli j = i;
        while (j < n && avilableKeys.count(S[j]) == 1)
            j++;
        lli length = j - i;
        ans += ((length) * (length + 1)) / 2;
        i = j;
    }
    cout << ans << '\n';
}
int main()
{
    solve();
    return 0;
}