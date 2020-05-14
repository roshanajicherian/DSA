#include <bits/stdc++.h>
using namespace std;
int solve()
{
    vector<pair<int, int>> A;
    int n = 0;
    cin >> n;
    //inuting the elements into the vector
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        A.push_back({x, y});
    }
    //This problem is simillar to the LIS problem. Here the comparison is done between the x-coordinate
    //of the first pair and the y coordinate of the second pair.
    int DP[n]; //memoization
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < n; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[j].second < A[i].first && DP[j] + 1 > DP[i])
                DP[i] = DP[j] + 1;
        }
    }
    int maxLIS = INT_MIN;
    for (int i = 0; i < n; i++)
        maxLIS = max(maxLIS, DP[i]);
    return maxLIS;
}
int main()
{

    cout << solve() << '\n';
    return 0;
}