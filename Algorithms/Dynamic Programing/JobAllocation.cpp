//Recursive Solution to the job allocation problem of GeekForGeeks

#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int startTime, finishTime, Profit;
};
bool byEndTime(Job a, Job b)
{
    return a.finishTime < b.finishTime;
}
int findLatestJob(Job A[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (A[j].finishTime <= A[i - 1].startTime)
            return j;
    }
    return -1;
}
int jobAllocationUtil(Job A[], int n)
{
    //At each step there are two possiblities
    //To include a job or to not include it.
    if (n == 1)
        return A[n - 1].Profit;
    int jobExcluded = jobAllocationUtil(A, n - 1);
    int jobIncluded = A[n - 1].Profit;
    int latestJob = findLatestJob(A, n);
    if (latestJob != -1)
        jobIncluded += jobAllocationUtil(A, latestJob + 1);
    return max(jobIncluded, jobExcluded);
}
void jobAllocation(Job A[], int n)
{
    sort(A, A + n, byEndTime);
    cout << jobAllocationUtil(A, n) << '\n';
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    jobAllocation(arr, n);
    return 0;
}