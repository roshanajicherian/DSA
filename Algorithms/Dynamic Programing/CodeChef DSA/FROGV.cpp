#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef long long int lli;
struct Frog
{
    lli id;
    lli postion;
} frg[MAXN];
lli DP[MAXN];
bool PostionSort(Frog x, Frog y)
{
    return x.postion < y.postion;
}
void solve()
{
    lli n = 0, k = 0, p = 0;
    cin >> n >> k >> p;
    for (lli i = 0; i < n; i++)
    {
        cin >> frg[i].postion;
        frg[i].id = i;
    }
    sort(frg, frg + n, PostionSort);
    DP[0] = frg[0].postion + k;
    for (lli i = 1; i < n; i++)
    {
        if (frg[i].postion - frg[i - 1].postion <= k)
            DP[frg[i].id] = DP[frg[i - 1].id];
        else
            DP[i] = frg[i].postion + k;
    }
    while (p--)
    {
        lli a = 0, b = 0;
        cin >> a >> b;
        if (DP[a] == DP[b])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}