#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli kadanesAlgo(vector<lli> A)
{
    lli currSum = 0;
    lli bestSum = INT_MIN;
    for (lli i = 0; i < A.size(); i++)
    {
        currSum += A[i];
        if (currSum > bestSum)
        {
            bestSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return bestSum;
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    vector<lli> A(n);
    lli arraySum = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        arraySum += A[i];
    }
    if (k == 1)
    {
        cout << kadanesAlgo(A) << '\n';
        return;
    }
    lli maximumSuffix = 0, maximumPrefix = 0, tempSum = 0;
    for (lli i = 0; i < n; i++)
    {
        tempSum += A[i];
        maximumPrefix = max(maximumPrefix, tempSum);
    }
    tempSum = 0;
    for (lli i = n - 1; i >= 0; i--)
    {
        tempSum += A[i];
        maximumSuffix = max(maximumSuffix, tempSum);
    }
    lli kadanes = kadanesAlgo(A);
    lli result = INT_MIN;
    if (arraySum < 0)
        result = max(maximumPrefix + maximumSuffix, kadanes);
    else
        result = max(maximumPrefix + maximumSuffix + (k - 2) * arraySum, kadanes);
    cout << result << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}