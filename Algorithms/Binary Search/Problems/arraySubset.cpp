#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> A, int x, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
            return mid;
        if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void solve()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int spaceLow = 0, spaceHigh = 0;
    spaceLow = binarySearch(A, B[0], 0, n - 1);
    spaceHigh = binarySearch(A, B[m - 1], 0, n - 1);
    if (spaceLow == -1 || spaceHigh == -1)
    {
        cout << "No\n";
        return;
    }
    int i = 1;
    while (i < m - 1)
    {
        if (binarySearch(A, B[i], spaceLow, spaceHigh) == -1)
        {
            cout << "No\n";
            return;
        }
        else
        {
            i++;
            spaceLow++;
        }
    }
    cout << "Yes\n";
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}