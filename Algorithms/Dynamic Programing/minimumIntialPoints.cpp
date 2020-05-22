#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3
int findMinimumCostDP(int grid[][COL])
{
    int DP[ROW][COL];
    DP[ROW - 1][COL - 1] = grid[ROW - 1][COL - 1] > 0 ? 1 : abs(grid[ROW - 1][COL - 1]) + 1;
    for (int i = ROW - 2; i >= 0; i--)
        DP[i][COL - 1] = max(DP[i + 1][COL - 1] - grid[i][COL - 1], 1);
    for (int i = COL - 2; i >= 0; i--)
        DP[ROW - 1][i] = max(DP[ROW - 1][i + 1] - grid[ROW - 1][i], 1);
    for (int i = ROW - 2; i >= 0; i--)
    {
        for (int j = COL - 2; j >= 0; j--)
        {
            int minimumExitDistance = min(DP[i + 1][j], DP[i][j + 1]);
            DP[i][j] = max(minimumExitDistance - grid[i][j], 1);
        }
    }
    return DP[0][0];
}
int main()
{
    int grid[ROW][COL] = {{-2, -3, 3},
                          {-5, -10, 1},
                          {10, 30, -5}};
    cout << findMinimumCostDP(grid) << '\n';
    return 0;
}