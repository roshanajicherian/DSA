#include <bits/stdc++.h>
using namespace std;
int findLPS(string A)
{
    int n = A.length();
    //zero-based indexing has been used. Can bec changed to 1 based indexing by minor tweaks.
    int DP[n][n];
    //if the subsequnce is of length 1 then the LPS is 1
    for (int i = 0; i < n; i++)
        DP[i][i] = 1;
    //BOTTOM UP APPROACH
    //Loop to select the subsequence. We start from subSequnce of length 2
    for (int subSequenceLength = 2; subSequenceLength <= n; subSequenceLength++)
    {
        //Loop to slect the starting character
        for (int start = 0; start < n - subSequenceLength + 1; start++)
        {
            //end character
            int end = start + subSequenceLength - 1;
            //if there are only two character in the string which are equal then LPS is 2
            if (A[start] == A[end] && subSequenceLength == 2)
                DP[start][end] = 2;
            //if the start and end character are the same then it adds 2 to the subsequence length
            else if (A[start] == A[end])
                DP[start][end] = 2 + DP[start + 1][end - 1];
            //else increase postion of start and decrease the postion of end and take max of them
            else
                DP[start][end] = max(DP[start + 1][end], DP[start][end - 1]);
        }
    }
    return DP[0][n - 1];
}
int main()
{
    string A;
    cin >> A;
    cout << findLPS(A) << '\n';
    return 0;
}