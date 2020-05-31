#include <bits/stdc++.h>
using namespace std;
int findMissingElement(int A[], int n)
{
    int commonDiffrence = (A[n - 1] - A[0]) / n;
    int low = 0, high =n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid + 1] - A[mid] != commonDiffrence)
            return A[mid] + commonDiffrence;
        else if (mid > 0 && A[mid] - A[mid - 1] != commonDiffrence)
            return A[mid - 1] + commonDiffrence;
        else if (A[mid] == A[0] + (mid * commonDiffrence))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << findMissingElement(A, n) << '\n';
    return 0;
}