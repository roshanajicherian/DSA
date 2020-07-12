#include <bits/stdc++.h>
using namespace std;

int findHighest(vector<int> A)
{
    int n = A.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid - 1] < A[mid] && A[mid + 1] < A[mid])
            return A[mid];
        else if (A[mid - 1] < A[mid] && A[mid + 1] > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << findHighest(A) << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}