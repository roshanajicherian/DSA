#include <bits/stdc++.h>
using namespace std;
int findMinOperations(int dimensionMatrix[], int endIndex)
{
    int dp[endIndex][endIndex];
    for (int i = 1; i < endIndex; i++)
        dp[i][i] = 0; //Base case which implies that a matrix when multipled with itself
    //has minimum cost of operations=0
    for (int subSequenceLength = 2; subSequenceLength < endIndex; subSequenceLength++)
    {
        for (int start = 1; start < endIndex - subSequenceLength + 1; start++)
        {
            int end = start + subSequenceLength - 1;
            for (int k = start; k < end; k++)
            {
                int temporaryMinimum = dp[start][k] * dp[start + 1][k] +
                                       (dimensionMatrix[start - 1] * dimensionMatrix[k] * dimensionMatrix[end]);
                if (temporaryMinimum < dp[start][end])
                    dp[start][end] = temporaryMinimum;
            }
        }
    }
    return dp[1][endIndex - 1];
}
int main()
{
    int numberofMatrices = 0;
    cin >> numberofMatrices;
    int dimensionMatrix[numberofMatrices];
    for (int i = 0; i < numberofMatrices; i++)
        cin >> dimensionMatrix[i];
    cout << findMinOperations(dimensionMatrix, numberofMatrices) << '\n';
    return 0;
}