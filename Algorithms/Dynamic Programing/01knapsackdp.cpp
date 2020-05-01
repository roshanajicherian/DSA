//DP approach to the 01 knapscack problem
#include <bits/stdc++.h>
using namespace std;
int knapsackDP(int weight[], int profit[], int numberOfObjects, int TotalWeight)
{
    int dp[numberOfObjects + 1][TotalWeight + 1];
    for (int i = 0; i <= numberOfObjects; i++)
    {
        for (int j = 0; j <= TotalWeight; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weight[i-1]<=j)
                dp[i][j] = max(profit[i - 1] + dp[i - 1][TotalWeight - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[numberOfObjects][TotalWeight];
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int totalWeight = 50;
    cout << knapsackDP(weight, profit, 3, totalWeight) << '\n';
    return 0;
}