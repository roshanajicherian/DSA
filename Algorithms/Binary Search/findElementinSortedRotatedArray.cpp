#include <bits/stdc++.h>
using namespace std;
int binarySearch(int A[], int x, int low, int high)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (A[mid] == x)
        return mid;
    if (x > A[mid])
        return binarySearch(A, x, mid + 1, high);
    return binarySearch(A, x, low, mid - 1);
}
int findPivot(int A[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return high;
    int mid = (low + high) / 2;
    if (mid < high && A[mid] > A[mid + 1])
        return mid;
    if (mid > low && A[mid] < A[mid - 1])
        return mid - 1;
    if (A[low] >= A[mid])
        return findPivot(A, low, mid - 1);
    return findPivot(A, mid + 1, high);
}
int pivotedBinarySearch(int A[], int n, int x)
{
    int pivot = findPivot(A, 0, n - 1);
    if (pivot == -1)
        return binarySearch(A, x, 0, n - 1);
    if (A[pivot] == x)
        return pivot;
    if (A[0] <= x)
        return binarySearch(A, x, 0, pivot - 1);
    return binarySearch(A, x, pivot + 1, n - 1);
}
int main()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;
    cout << "Index of the element is : " << pivotedBinarySearch(arr1, n, key) << '\n';
    return 0;
}