#include <bits/stdc++.h>
using namespace std;
void findMinimumCoins(int coins[], int m, int V)
{
    int DP[V + 1];
    DP[0] = 0;
    for (int i = 1; i <= V; i++)
        DP[i] = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int cost = DP[i - coins[j]];
                if (cost != INT_MAX && cost + 1 < DP[i])
                    DP[i] = cost + 1;
            }
        }
    }
    cout << DP[V] << '\n';
}
int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    findMinimumCoins(coins, m, V);
    return 0;
}