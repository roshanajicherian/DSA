#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
int kadanesAlgo(int temp[], int *start, int *end)
{
    int finalMax = INT_MIN;
    *end = -1;
    int sumEndingHere = 0, localStart = 0;
    for (int i = 0; i < COL; i++)
    {
        sumEndingHere += temp[i];
        if (sumEndingHere < 0)
        {
            sumEndingHere = 0;
            localStart = i + 1;
        }
        else if (sumEndingHere > finalMax)
        {
            finalMax = sumEndingHere;
            *start = localStart;
            *end = i;
        }
    }
    if (*end != -1)
        return finalMax;
    *start = 0, *end = 0;
    finalMax = temp[0];
    for (int i = 1; i < COL; i++)
    {
        if (temp[i] > finalMax)
        {
            finalMax = temp[i];
            *start = i;
            *end = i;
        }
    }
    return finalMax;
}
void rectangleSum(int A[][COL])
{
    int left = 0, right = 0;
    int finalStart = 0, finalEnd = 0, finalLeft = 0, finalRight = 0, finalMax = INT_MIN;
    int tempStart = 0, tempEnd = 0, tempMax = INT_MIN;
    int temp[COL];
    for (int left = 0; left < COL; left++)
    {
        memset(temp, 0, sizeof(temp));
        for (int right = left; right < COL; right++)
        {
            for (int i = 0; i < ROW; i++)
                temp[i] += A[i][right];
            tempMax = kadanesAlgo(temp, &tempStart, &tempEnd);
            if (tempMax > finalMax)
            {
                finalMax = tempMax;
                finalStart = tempStart;
                finalEnd = tempEnd;
                finalLeft = left;
                finalRight = right;
            }
        }
    }
    cout << finalMax << '\n';
}
int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}};
    rectangleSum(M);
    return 0;
}