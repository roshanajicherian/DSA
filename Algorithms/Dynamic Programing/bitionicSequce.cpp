//Dynamic Programming Solution to Longest Bitionic Sequence
#include <bits/stdc++.h>
using namespace std;
int findLongestBitionic(int A[], int n)
{
    //Find longest increasing and longest decreasing subsequence and take the max of them
    //Lookup tables to store the values of LIS and LDS
    int DPIncreasing[n], DPDecreasing[n];
    //Finding LIS
    for (int i = 0; i < n; i++)
    {
        DPIncreasing[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && DPIncreasing[j] + 1 > DPIncreasing[i])
                DPIncreasing[i] = DPIncreasing[j] + 1;
        }
    }
    //Finding LDS
    for (int i = n - 1; i >= 0; i--)
    {
        DPDecreasing[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (A[i] > A[j] && DPDecreasing[j] + 1 > DPDecreasing[i])
                DPDecreasing[i] = DPDecreasing[j] + 1;
        }
    }
    //Taking the maximum value
    int maxi = DPIncreasing[0] + DPDecreasing[0] - 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, DPIncreasing[i] + DPDecreasing[i] - 1);
    }
    return maxi;
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << findLongestBitionic(A, n) << '\n';
    return 0;
}