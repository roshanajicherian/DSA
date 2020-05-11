//Soultion to Partition problem (DP-18) of GeekForGeeks
#include <bits/stdc++.h>
using namespace std;
bool findPartitionSum(int A[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += A[i];
    if (totalSum & 1)
        return false;
    totalSum /= 2;

    //find if any subset of the array adds up to give sum/2
    //DP can be used for this.
    //At each step there are two choices
    //To include the (n-1)th and move to the (0n-2)th and reduce the total sum by A[n-1]
    //OR to not include the (n-1)th element and move to the (n-2)th element
    //Since the solution depends upon two parameters(sum and end positon) the memoization requires a
    //2D matrix(The dimension of the matrix depends on the parameters on which the DP depends)
    bool DP[totalSum + 1][n + 1];
    for (int i = 0; i <= n; i++)
        DP[0][i] = true;
    for (int i = 1; i <= totalSum; i++)
        DP[i][0] = false;
    for (int i = 1; i <= totalSum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            DP[i][j] = DP[i][j - 1];
            if (i >= A[j])
                DP[i][j] = DP[i][j] || DP[i - A[j]][j - 2];
        }
    }
    return DP[totalSum / 2][n];
}
int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    if (findPartitionSum(A, n))
        cout << "Yes\n";
    else
        cout << "NO\n";
    return 0;
}