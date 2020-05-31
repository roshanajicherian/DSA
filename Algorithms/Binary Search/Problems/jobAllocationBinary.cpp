//Solution to job allocation problem int O(nlogn) time
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int startTime, endTime, profit;
};
bool byEndTime(Job A, Job B)
{
    return A.endTime < B.endTime;
}
int findLatest(Job A[], int index)
{
    int low = 0, high = index - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid].endTime <= A[index].startTime)
        {
            if (A[mid + 1].endTime <= A[index].startTime)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int jobAllocataion(Job A[], int n)
{
    sort(A, A + n, byEndTime);
    int DP[n];
    memset(DP, 0, sizeof(DP));
    DP[0] = A[0].profit;
    for (int i = 1; i < n; i++)
    {
        int includedProfit = A[i].profit;
        int latestIndex = findLatest(A, i);
        if (latestIndex != -1)
            includedProfit += DP[latestIndex];
        DP[i] = max(DP[i - 1], includedProfit);
    }
    return DP[n - 1];
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << jobAllocataion(arr, n) << '\n';
    return 0;
}