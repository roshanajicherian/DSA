#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int startTime, endTime, profit;
};
bool byEndTime(Job a, Job b)
{
    return a.endTime < b.endTime;
}
int findLatest(Job A[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (A[j].endTime <= A[i].startTime)
            return j;
    }
    return -1;
}
int jobAllocation(Job A[], int n)
{
    sort(A, A + n, byEndTime);
    int DP[n];
    memset(DP, 0, sizeof(DP));
    DP[0] = A[0].profit;
    for (int i = 1; i < n; i++)
    {
        int includeProfit = A[i].profit;
        int latest = findLatest(A, i);
        if (latest != -1)
            includeProfit += DP[latest];
        DP[i] = max(DP[i - 1], includeProfit);
    }
    return DP[n - 1];
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << jobAllocation(arr, n) << '\n';
    return 0;
}