// Solution to Fibonacci Finding(Easy) problem of HackerRank
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
lli identityMatrix[3][3];
lli transitionMatrix[3][3];
void matrixMultiplication(lli A[3][3], lli B[3][3], lli n)
{
    lli res[n + 1][n + 1];
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            res[i][j] = 0;
            for (lli k = 1; k <= n; k++)
            {
                int x = (A[i][k] * B[k][j]) % MOD;
                res[i][j] = (res[i][j] + x) % MOD;
            }
        }
    }
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}
void solve()
{
    lli baseVals[3];
    lli n = 0;
    cin >> baseVals[1] >> baseVals[2] >> n;
    n += 1; //for 1 based indexing
    if (n <= 2)
    {
        cout << baseVals[n] << '\n';
        return;
    }
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            if (i == j)
                identityMatrix[i][j] = 1;
            else
                identityMatrix[i][j] = 0;
        }
    }
    transitionMatrix[1][1] = 0;
    transitionMatrix[1][2] = transitionMatrix[2][1] = transitionMatrix[2][2] = 1;
    n--; //for finding t^n-1
    while (n)
    {
        if (n & 1)
            matrixMultiplication(identityMatrix, transitionMatrix, 2);
        n >>= 1;
        matrixMultiplication(transitionMatrix, transitionMatrix, 2);
    }
    for (lli i = 1; i <= 2; i++)
        for (lli j = 1; j <= 2; j++)
            transitionMatrix[i][j] = identityMatrix[i][j];

    lli res = ((baseVals[1] * transitionMatrix[1][1])%MOD + (baseVals[2] * transitionMatrix[2][1])%MOD) % MOD;
    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}