#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    vector<int> counter(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        counter[A[i]]++;
    }
    int maxCount = *max_element(counter.begin(), counter.end());
    int diffrentElements = (n + 1) - count(counter.begin(), counter.end(), 0);
    int result = max(min(maxCount, diffrentElements - 1), min(maxCount - 1, diffrentElements));
    cout << result << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}