#include <bits/stdc++.h>
using namespace std;
#define r 6
#define c 5
void maximumSquareDP(int A[r][c])
{

    //Check G4G for solutions
    int DP[r][c];
    for (int i = 0; i < r; i++)
        DP[i][0] = A[i][0];
    for (int i = 0; i < c; i++)
        DP[0][i] = A[0][i];
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (A[i][j] == 1)
                DP[i][j] = min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j])) + 1;
            else
                DP[i][j] = 0;
        }
    }
    int rMax = 0, jMax = 0, DPMAX = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (DP[i][j] > DPMAX)
            {
                DPMAX = DP[i][j];
                rMax = i;
                jMax = j;
            }
        }
    }
    for (int i = rMax; i > rMax - DPMAX; i--)
    {
        for (int j = jMax; j > jMax - DPMAX; j--)
            cout << A[i][j] << ' ';
        cout << '\n';
    }
}
void solve()
{
    int A[r][c] = {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    maximumSquareDP(A);
}
int main()
{

    solve();
    return 0;
}