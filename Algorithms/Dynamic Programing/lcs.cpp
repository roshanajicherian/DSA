#include <bits/stdc++.h>
using namespace std;

int findLCS(string A, string B)
{
    //Finding LCS of  two strings using bottom up approach
    int m = A.length();
    int n = B.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            //No subsequence can be formed of length 0
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            //If the end characters of both the string are the same
            //include it in the solution
            else if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // If the end characters are not same go in both the directions i.e
            // find lcs if one character from A is removed and lcs
            // if one charcter from B is removed.Take max of it.
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string A, B;
    cin >> A >> B;
    int m = A.length();
    int n = B.length();
    cout << findLCS(A, B) << '\n';
    return 0;
}