#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int maxSum = 0;
    set<int> subsequence;
    int i = 0;
    while (i < n)
    {
        if (A[i] < 0)
        {
            while (A[i] < 0 && i < n)
            {
                subsequence.insert(A[i]);
                i++;
            }
                }
        else
        {
            while (A[i] > 0 && i < n)
            {
                subsequence.insert(A[i]);
                i++;
            }
        }
        maxSum += *subsequence.rbegin();
        subsequence.clear();
    }
    cout << maxSum << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}