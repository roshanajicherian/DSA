#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int noOfWays[MAXN + 1];
void init()
{
    noOfWays[1] = 1;
    noOfWays[2] = 2;
    for (int i = 3; i <= MAXN; i++)
        noOfWays[i] = noOfWays[i - 1] + noOfWays[i - 2];
}
void solve()
{
    int n = 0;
    cin >> n;
    cout << noOfWays[n] << '\n';
}
int main()
{
    init();
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}