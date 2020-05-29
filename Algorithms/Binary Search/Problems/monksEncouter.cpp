#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a = 0, b = 0, c = 0, k = 0;
lli functionCalc(lli x)
{
    return a * x * x + b * x + c;
}
lli bSearch(lli k)
{
    if (c >= k)
        return 0;
    lli low = 0;
    //check the function to find the reason for high
    lli high = ceil(sqrt(k));
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        lli x = functionCalc(mid - 1);
        lli y = functionCalc(mid);
        if (x < k && y >= k)
            return mid;
        else if (y < k)
            low = mid + 1;
        else if (y > k)
            high = mid - 1;
    }
    return -1;
}
void solve()
{
    cin >> a >> b >> c >> k;
    //we can use binary search over here because the function ax^2+bx+c is a monotomic strictly increrasing function
    cout << bSearch(k) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}