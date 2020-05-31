#include <bits/stdc++.h>
using namespace std;
int findRange(int A[], int n, int x)
{
    int i = 1;
    while (i < n && A[i] <= x)
        i *= 2;
    return i;
}
int binarySearch(int A[], int low, int high, int x)
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void exponentialSearch(int A[], int n, int x)
{
    if (A[0] == x)
        cout << 0 << '\n';
    int range = findRange(A, n, x);
    cout << "Element found at index : " << binarySearch(A, range / 2, min(range, n), x) << '\n';
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int x = 0;
    cin >> x;
    exponentialSearch(A, n, x);
    return 0;
}