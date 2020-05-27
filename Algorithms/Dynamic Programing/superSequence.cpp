#include <bits/stdc++.h>
using namespace std;
int findLCS(string A, string B)
{
    int m = A.length();
    int n = B.length();
    int DP[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    return DP[m][n];
}
int findSuperSequence(string A, string B)
{
    int n = A.length();
    int m = B.length();
    //Length of SCS=Length of the strings-LCS of the strings
    int l = findLCS(A, B);
    return m + n - l;
}
int main()
{
    string A, B;
    cin >> A >> B;
    cout << findSuperSequence(A, B) << '\n';
    return 0;
}