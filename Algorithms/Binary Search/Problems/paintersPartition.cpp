//Recursive solution to Painter's Partition Problem
#include <bits/stdc++.h>
using namespace std;
//k= No of painters
//n= Length of the array under consideration
int sum(int A[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += A[i];
    }
    return sum;
}
int paintersPartition(int A[], int n, int k)
{
    if (k == 1)
        return sum(A, 0, n - 1);
    if (n == 1)
        return A[0];
    int result = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        result = min(result, max(paintersPartition(A, i, k - 1), sum(A, i, n - 1)));
    }
    return result;
}
int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << paintersPartition(arr, n, k) << endl;
    return 0;
}