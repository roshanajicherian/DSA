//Solution to Bishu and Soldiers Question on HackerEarth
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli binarySearch(vector<lli> A, lli x)
{
    lli low = 0, high = A.size() - 1;
    lli ans = 0;
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        if (A[mid] <= x)
        {
            low = mid + 1;
            ans = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    vector<lli> prefixSum(n);
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    prefixSum[0] = A[0];
    for (lli i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + A[i];
    lli q = 0;
    cin >> q;
    while (q--)
    {
        lli powerOfBishu = 0;
        cin >> powerOfBishu;
        if (A[n - 1] < powerOfBishu)
        {
            cout << n << ' ' << prefixSum[n - 1] << '\n';
        }
        else if (A[0] > powerOfBishu)
        {
            cout << 0 << ' ' << 0 << '\n';
        }
        else
        {
            lli maxIndex = binarySearch(A, powerOfBishu);
            cout << maxIndex << ' ' << prefixSum[maxIndex-1] << '\n';
        }
    }
    return 0;
}