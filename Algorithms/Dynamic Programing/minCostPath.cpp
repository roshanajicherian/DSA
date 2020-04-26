#include <bits/stdc++.h>
using namespace std;
const int r = 3;
const int c = 3;
int findMinCost(int costMatrix[][c], int x, int y)
{
    int dp[r][c];
    dp[0][0] = costMatrix[0][0];
    for (int i = 1; i <= x; i++)
        dp[i][0] = dp[i - 1][0] + costMatrix[i][0];
    for (int j = 1; j <= y; j++)
        dp[0][j] = dp[0][j - 1] + costMatrix[0][j];
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            //One can reach a coordinates (x,y) in three possible directions
            //From 1)(i-1,j-1)  2)(i,j-1)  3)(i-1,j)
            //We chose the path which gives the minimum result
            dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + costMatrix[i][j];
        }
    }
    return dp[x][y];
}
int main()
{
    int costMatrix[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> costMatrix[i][j];
    cout << findMinCost(costMatrix, 2, 2) << '\n';
    return 0;
}