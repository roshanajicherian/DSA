// Solution to CodeForces Round 629 Div 3 B
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    lli maximumElement = INT_MIN, minimumElement = INT_MAX;
    vector<lli> A(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        maximumElement = max(maximumElement, A[i]);
        minimumElement = min(minimumElement, A[i]);
    }
    cout << maximumElement - minimumElement << ' ';
    if (maximumElement == minimumElement)
        cout << n * (n - 1) / 2 << '\n';
    else
    {
        lli countMax = 0, countMin = 0;
        for (lli i = 0; i < n; i++)
        {
            countMax += (maximumElement == A[i]);
            countMin += (minimumElement == A[i]);
        }
        cout << countMin * countMax << '\n';
    }
}
int main()
{

    solve();
    return 0;
}