#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int maxSum = 0, windowSum = 0;
    for (int i = 0; i < k; i++)
        maxSum += A[i];
    windowSum = maxSum;
    for (int i = k; i < n; i++)
    {
        windowSum = windowSum + A[i] - A[i - k];
        maxSum = max(windowSum, maxSum);
    }
    cout << maxSum << '\n';
    return 0;
}