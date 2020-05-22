#include <bits/stdc++.h>
using namespace std;
int findNonDecreasing(int n)
{
    //2D array for memoization.
    //DP[i][j]=no of non decreasing numbers of length j ending with i
    int DP[10][n + 1];
    for (int i = 0; i <= 10; i++)
        DP[i][1] = 1;
    //Count of non decreasing numbers of length n=
    //no of non decreasing numbers of length n-1 ending wiht 9+
    //no of non decreasing numbers of length n-1 ending with 8+.....
    for (int digit = 0; digit < 10; digit++)
    {
        for (int length = 2; length <= n; length++)
        {
            DP[digit][length] = 0;
            for (int x = 0; x <= digit; x++)
            {
                DP[digit][length] += DP[x][length - 1];
            }
        }
    }
    int finalCount = 0;
    for (int i = 0; i < 10; i++)
    {
        finalCount += DP[i][n];
    }
    return finalCount;
}
int main()
{
    int n = 0;
    cin >> n;
    cout << findNonDecreasing(n) << '\n';
    return 0;
}