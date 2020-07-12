#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> A, int x)
{
    int low = 0, high = A.size() - 1, minimumDifference = INT_MAX, index = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (abs(A[mid] - x) < minimumDifference)
        {
            minimumDifference = abs(A[mid] - x);
            index = mid;
            low = mid + 1;
        }
        else if (abs(A[mid] - x) > minimumDifference)
            high = mid - 1;
    }
    return A[index];
}
void solve()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int ans = binarySearch(A, k);
    cout << ans << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}