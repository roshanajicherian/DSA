#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 3
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};
int findWaysDP(char keyPad[][COL], int n)
{
    if (keyPad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 10;
    int DP[10][n + 1];
    int ro = 0, co = 0;
    for (int i = 0; i < 10; i++)
    {
        DP[i][0] = 0;
        DP[i][1] = 1;
    }
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (keyPad[i][j] != '*' && keyPad[i][j] != '#')
                {
                    int number = keyPad[i][j] - '0';
                    DP[number][length] = 0;
                    for (int moves = 0; moves < 5; moves++)
                    {
                        ro = i + row[moves];
                        co = j + col[moves];
                        if ((ro >= 0 && ro <= 3) && (co >= 0 && co <= 2) && (keyPad[ro][co] != '#' && keyPad[ro][co] != '*'))
                        {
                            int nextNum = keyPad[ro][co] - '0';
                            DP[number][length] += DP[nextNum][length - 1];
                        }
                    }
                }
            }
        }
    }
    int totalCount = 0;
    for (int i = 0; i < 10; i++)
    {
        totalCount += DP[i][n];
    }
    return totalCount;
}
int main()
{
    char keyPad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    cout << findWaysDP(keyPad, 5) << '\n';
    return 0;
}