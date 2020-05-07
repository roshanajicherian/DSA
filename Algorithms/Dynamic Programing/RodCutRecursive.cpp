#include <bits/stdc++.h>
using namespace std;
int cutRod(int A[], int n)
{
    if (n <= 0)
        return 0;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, A[i] + cutRod(A, n - i - 1));
    return maxVal;
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << cutRod(A, n) << '\n';
    return 0;
}