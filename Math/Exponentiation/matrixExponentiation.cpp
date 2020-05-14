#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MOD 1000000007
typedef long long int lli;
lli ar[MAXN][MAXN], I[MAXN][MAXN];
void matrixMultiplication(lli A[][MAXN], lli B[][MAXN], lli n)
{
    lli res[n + 1][n + 1];
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            res[i][j] = 0;
            for (lli k = 1; k <= n; k++)
                res[i][j] = (res[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
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
void matrixPrint(lli A[][MAXN], lli n)
{
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
            cout << A[i][j] << ' ';
        cout << '\n';
    }
}
void matrixPower(lli A[][MAXN], lli n, lli power)
{
    //Intialaizing identity matrix
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    //For exponentation run a loop for power times and mulitply the matrix with itself
    // for (lli i = 0; i < power; i++)
    //     matrixMultiplication(I, A, n);
    while (power)
    {
        if (power & 1)
            matrixMultiplication(I, A, n);
        power >>= 1;
        matrixMultiplication(A, A, n);
    }
    for (lli i = 1; i <= n; i++)
        for (lli j = 1; j <= n; j++)
            A[i][j] = I[i][j];
}
void solve()
{
    lli n = 0, power = 0;
    cin >> n >> power;
    for (lli i = 1; i <= n; i++)
        for (lli j = 1; j <= n; j++)
            cin >> ar[i][j];
    matrixPower(ar, n, power);
    matrixPrint(ar, n);
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