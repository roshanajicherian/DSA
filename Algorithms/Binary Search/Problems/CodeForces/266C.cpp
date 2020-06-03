#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    lli totalSum = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        totalSum += A[i];
    }
    if (totalSum % 3 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    totalSum /= 3;
    vector<lli> count(n, 0);
    lli tempSum = 0;
    for (lli i = n - 1; i >= 0; i--)
    {
        tempSum += A[i];
        if (tempSum == totalSum)
            count[i] = 1;
    }
    for (lli i = n - 2; i >= 0; i--)
        count[i] += count[i + 1];
    tempSum = 0;
    lli answer = 0;
    for (lli i = 0; i < n - 2; i++)
    {
        tempSum += A[i];
        if (tempSum == totalSum)
            answer += count[i + 2];
    }
    cout << answer << '\n';
}
int main()
{
    solve();
    return 0;
}