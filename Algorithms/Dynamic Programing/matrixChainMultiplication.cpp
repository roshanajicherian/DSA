#include <bits/stdc++.h>
using namespace std;
//The following is the recursive solution of Matrix Chain Multiplication without memoization
int findMinOperations(int dimensionMatrix[], int startIndex, int endIndex)
{
    if (startIndex == endIndex)
        return 0;
    int count = 0;
    int minimumOperations = INT_MAX;
    for (int i = startIndex; i < endIndex; i++)
    {
        count = findMinOperations(dimensionMatrix, startIndex, i) +
                findMinOperations(dimensionMatrix, i + 1, endIndex) +
                dimensionMatrix[startIndex - 1] * dimensionMatrix[i] * dimensionMatrix[endIndex];
        minimumOperations = min(minimumOperations, count);
    }
    return minimumOperations;
}
int main()
{
    int numberOfMatrices = 0;
    cin >> numberOfMatrices;
    int dimensionMatrix[numberOfMatrices];
    for (int i = 0; i < numberOfMatrices; i++)
        cin >> dimensionMatrix[i];
    cout << findMinOperations(dimensionMatrix, 1, numberOfMatrices - 1) << '\n';

    return 0;
}