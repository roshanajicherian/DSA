#include <bits/stdc++.h>
using namespace std;
int findSum(vector<int> freq, int start, int end)
{
    int s = 0;
    for (int i = start; i <= end; i++)
        s += freq[i];
    return s;
}
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    int DP[n][n];
    //if only a single node is present
    for (int i = 0; i < n; i++)
        DP[i][i] = freq[i];
    for (int sequenceLength = 2; sequenceLength <= n; sequenceLength++)
    {
        for (int start = 0; start <= n - sequenceLength + 1; start++)
        {
            int end = start + sequenceLength - 1;
            DP[start][end] = INT_MAX;
            for (int root = start; root <= end; root++)
            {
                int c = ((root > start) ? DP[start][root - 1] : 0) + ((root < end) ? DP[root + 1][end] : 0) + findSum(freq, start, end);
                DP[start][end] = min(DP[start][end], c);
            }
        }
    }
    cout << DP[0][n - 1] << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}