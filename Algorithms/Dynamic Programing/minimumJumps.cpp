#include <bits/stdc++.h>
using namespace std;
int minJumpsDP(vector<int> A, int n)
{
    //Base cases
    if (n == 0 || A[0] == INT_MAX)
        return INT_MAX;
    //DP array for storing the results
    int DP[n];
    //No jumps are required at the intial position
    DP[0] = 0;
    //Find out the minimum possible to each block and using this result to find the minimum possible distance to the end of the array
    for (int i = 1; i < n; i++)
    {
        DP[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            //Checking if the particular block can be reached from a block j
            if (j + A[j] >= i && DP[j] != INT_MAX)
            {
                DP[i] = min(DP[i], DP[j] + 1);
                //  break;
            }
        }
    }
    return DP[n - 1];
}
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        A.push_back(temp);
    }
    cout << minJumpsDP(A, n) << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}