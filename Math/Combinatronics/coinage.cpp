//Soltion to coinage problem of HackerRank
#include <bits/stdc++.h>
using namespace std;
int noOfWays[1001];
void solve()
{
    int S = 0, a = 0, b = 0, c = 0, d = 0;
    cin >> S >> a >> b >> c >> d;
    memset(noOfWays, 0, sizeof(noOfWays));
    for (int bCount = 0; (bCount <= b && bCount * 2 <= S); bCount++)
    {
        for (int aCount = 0; (aCount <= a && aCount + bCount * 2 <= S); aCount++)
            noOfWays[aCount + bCount * 2]++;
    }
    int result = 0;
    for (int cCount = 0; (cCount <= c && cCount * 5 <= S); cCount++)
    {
        for (int dCount = 0; (dCount <= d && cCount * 5 + dCount * 10 <= S); dCount++)
            result += noOfWays[S - cCount * 5 - dCount * 10];
    }
    cout << result << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}