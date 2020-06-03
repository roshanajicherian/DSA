#include <bits/stdc++.h>
using namespace std;
int findSum(int A[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += A[i];
    }
    return sum;
}
int paintersPartitionDP(int A[], int n, int k)
{
    int DP[k + 1][n + 1];
    for (int i = 1; i <= k; i++)
        DP[i][1] = A[0];
    for (int i = 1; i <= n; i++)
        DP[1][i] = findSum(A, 0, i - 1);
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int best = INT_MAX;
            for (int p = 1; p <= j; p++)
            {
                best = min(best, max(DP[i - 1][p], findSum(A, p, j - 1)));
            }
            DP[i][j] = best;
        }
    }
    return DP[k][n];
}
int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << paintersPartitionDP(arr, n, k) << endl;
    return 0;
}