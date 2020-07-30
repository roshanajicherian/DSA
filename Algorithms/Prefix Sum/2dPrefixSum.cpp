#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3
void findPrefixSum(int A[ROW][COL])
{
    int prefixSum[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == 0 && j == 0)
                prefixSum[i][j] = A[i][j];
            else if (i == 0 && j > 0)
                prefixSum[i][j] = prefixSum[i][j - 1] + A[i][j];
            else if (i > 0 && j == 0)
                prefixSum[i][j] = prefixSum[i - 1][j] + A[i][j];
            else
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + A[i][j];
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << prefixSum[i][j] << ' ';
        cout << '\n';
    }
}
int main()
{
    int A[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cin >> A[i][j];
    }
    findPrefixSum(A);

    return 0;
}