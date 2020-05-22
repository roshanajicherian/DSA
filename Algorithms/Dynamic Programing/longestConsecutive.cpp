#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};
int DP[ROW][COL];
bool isValid(int i, int j)
{
    if (i < 0 || j < 0 || i >= ROW || j >= COL)
        return false;
    return true;
}
bool isConsective(char prev, char curr)
{
    if (curr - prev == 1)
        return true;
    return false;
}
int findLongestPathUtil(char matrix[][COL], char previousLetter, int start, int end)
{
    if (!(isValid(start, end)) || !(isConsective(previousLetter, matrix[start][end])))
        return 0;
    if (DP[start][end] != -1)
        return DP[start][end];
    int ans = INT_MIN;
    for (int k = 0; k < 8; k++)
    {
        ans = max(ans, 1 + findLongestPathUtil(matrix, matrix[start][end], start + x[k], end + y[k]));
    }
    DP[start][end] = ans;
    return DP[start][end];
}
int findLongestPath(char matrix[][COL], char startLetter)
{
    memset(DP, -1, sizeof(DP));
    int ans = INT_MIN;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (matrix[i][j] == startLetter)
            {
                for (int k = 0; k < 8; k++)
                {
                    ans = max(ans, 1 + findLongestPathUtil(matrix, startLetter, i + x[k], j + y[k]));
                }
            }
        }
    }
    return ans;
}
int main()
{
    char matrix[ROW][COL] = {{'a', 'c', 'd'},
                             {'h', 'b', 'a'},
                             {'i', 'g', 'f'}};

    cout << findLongestPath(matrix, 'a') << '\n';
    return 0;
}