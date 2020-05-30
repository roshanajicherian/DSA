#include <bits/stdc++.h>
using namespace std;
bool isFeasible(vector<int> A, int n, int m, int minimumSum)
{
    int studentsRequired = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > minimumSum)
            return false;
        if (currentSum + A[i] > minimumSum)
        {
            studentsRequired++;
            currentSum = A[i];
            if (studentsRequired > m)
                return false;
        }
        else
            currentSum += A[i];
    }
    return true;
}
int binarySearch(vector<int> A, int low, int high, int m)
{
    int res = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(A, A.size(), m, mid))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
void solve()
{
    int n = 0, m = 0, sum = 0;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    int low = 0;
    int high = sum;
    cout<<binarySearch(A, low, high, m)<<'\n';
}
int main()
{
    solve();
    return 0;
}