//Recursive solution to the numeric Key Pad Problem of GFG
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 3
//arrays for easy traversal to the neighbouring locations
int row[] = {0, -1, 1, 0, 0};
int col[] = {0, 0, 0, 1, -1};
int findWaysUtil(char keypad[][COL], int n, int r, int c)
{
    //Base cases
    if (keypad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 1;
    int totalCount = 0;
    int i = 0, j = 0;
    //move to all the possible neighbours a keypad number
    for (int move = 0; move < 5; move++)
    {
        i = r + row[move];
        j = c + col[move];
        //condtions to check if the keypad number is valid
        if ((i >= 0 && i <= 3) && (j >= 0 && j <= 2) && (keypad[i][j] != '*' && keypad[i][j] != '#'))
            //The count of the numbers of length n which can be formed using
            //a  number is equal to the number of ways a number of length n-1 can
            //be formed from a number of length n-1.
            //The recursive sum from n-1 till 1 gives the required result.
            totalCount += findWaysUtil(keypad, n - 1, i, j);
    }
    return totalCount;
}
int findWays(char keypad[][COL], int n)
{
    if (keypad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 10;
    int totalCount = 0;
    //Considering each number as the starting postion
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
                totalCount += findWaysUtil(keypad, n, i, j);
        }
    }
    return totalCount;
}
int main()
{
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    cout << findWays(keypad, 5) << '\n';
    return 0;
}