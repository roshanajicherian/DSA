#include <bits/stdc++.h>
using namespace std;
int findCoinChange(int cashAvialble, int coinDenominations[], int numberofCoins)
{
    int dp[cashAvialble + 1][numberofCoins];
    for (int i = 0; i <= numberofCoins; i++)
        dp[0][i] = 1;
    //if the cash available is 0 then there is only one way to obatain change.
    //More specifically to obatin a change of 0.
    for (int i = 1; i <= cashAvialble; i++)
    {
        for (int j = 0; j < numberofCoins; j++)
        {
            int coinInculdedWays = 0, coinNotIncludedWays = 0;
            //If the coin can be included in the solution
            if (i - coinDenominations[j] >= 0)
                coinInculdedWays = dp[i - coinDenominations[j]][j];
            else
                coinInculdedWays = 0;
            //If the coin is not included in the solution
            if (j >= 1) //Conditon so as to prevent segmentation fault.
                coinNotIncludedWays = dp[i][j - 1];
            dp[i][j] = coinInculdedWays + coinNotIncludedWays;
        }
    }
    return dp[cashAvialble][numberofCoins - 1];
}
int main()
{
    int cashAvialable = 0;
    cin >> cashAvialable;
    int numberofCoins = 0;
    cin >> numberofCoins;
    int coinDenominations[numberofCoins];
    for (int i = 0; i < numberofCoins; i++)
        cin >> coinDenominations[i];
    cout << findCoinChange(cashAvialable, coinDenominations, numberofCoins) << '\n';
    return 0;
}