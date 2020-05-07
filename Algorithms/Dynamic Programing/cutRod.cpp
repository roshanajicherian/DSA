#include <bits/stdc++.h>
using namespace std;
int rodCutDP(int price[], int n)
{
    //Lookup table to store the result
    int DP[n + 1];
    //if the length of the rod is 0 then the maximum profit which can be obtained is 0
    DP[0] = 0;
    int maxVal = INT_MIN;
    int i = 0, j = 0;
    //BOTTOM UP APPROACH
    //Loop to decide the intial length of the  rod
    for (i = 1; i <= n; i++)
    {
        int maxVal = INT_MIN;
        //Loop to split the rod into pieces
        for (j = 0; j < i; j++)
        {
            maxVal = max(maxVal, price[j] + DP[i - j - 1]);
        }
        DP[i] = maxVal;
    }
    return DP[n];
}
int main()
{
    int n = 0;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << rodCutDP(price, n) << '\n';
    return 0;
}