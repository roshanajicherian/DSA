//Solution to SONYASEG problem of CodeChef.
//Find the number of ways of choosing k segments from the total
//n segments such that there does not exist any intersetion between any of chosen segments
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD (int)(1e9 + 7)
#define MAXN (int)(4e5 + 10)
lli factorial[MAXN + 1];
lli fastPower(lli base, lli exponent)
{
    base = base % MOD;
    if (base == 0)
        return 1;
    lli result = 1;
    while (exponent)
    {
        if (exponent & 1)
            result = (result * base) % MOD;
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}
lli inverse(lli x)
{
    return fastPower(x, MOD - 2);
}
void init()
{
    factorial[0] = factorial[1] = 1;
    for (lli i = 2; i <= MAXN; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
}
lli binomialCoeffecient(lli n, lli r)
{
    if (n < r)
        return 0;
    //nCr=n!/(n-r)!(r)!
    return ((factorial[n] * inverse(factorial[n - r])) % MOD * (inverse(factorial[r])) % MOD) % MOD;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    pair<lli, lli> Points[n + 1];
    for (lli i = 1; i <= n; i++)
    {
        lli x1 = 0, x2 = 0;
        cin >> x1 >> x2;
        Points[i].first = x1;
        Points[i].second = x2;
    }
    //Sorting the array of segments in increasing order of r for efficent calcutlation
    //All of the k segments intersect when min(r(1)+r(2)+... r(k-1))>=l(i)
    //Number of ways to choses the segments such that they donot intersect=
    //Total number of ways of froming the segments - Number of ways the segments  intersect
    sort(Points + 1, Points + n + 1, cmp);
    //multiset for comparing the points. The multiset could have both the left and right points
    //but haveing the left points in unecessary.
    multiset<lli> P;
    lli intersectingWays = 0;
    for (lli i = 1; i <= n; i++)
    {
        //If the segments do not intersect then remove that minimum point from the multiset and try
        //with the next minimum point
        while (!P.empty() && *P.begin() < Points[i].first)
            P.erase(P.begin());
        intersectingWays = (intersectingWays + binomialCoeffecient(P.size(), k - 1)) % MOD;
        P.insert(Points[i].second);
    }
    lli totalWays = binomialCoeffecient(n, k);
    lli result = totalWays - intersectingWays;
    cout << result << '\n';
}
int main()
{
    init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}