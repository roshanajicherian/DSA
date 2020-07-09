// Solution to Chef and Weird Queries Problem on Codechef

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    // n=Y. Find number of possible A and B such that A^2+B<=Y
    // ==> A^2<=Y-B
    // Since B has a maximum limit of 700 we can iterate over Y-B to check if a sqaure root exists
    lli ans = 0;
    for (lli i = 1; i <= 700; i++)
    {
        if (n - i <= 0)
            break;
        ans += floor(sqrt(n - i));
    }
    cout << ans << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}