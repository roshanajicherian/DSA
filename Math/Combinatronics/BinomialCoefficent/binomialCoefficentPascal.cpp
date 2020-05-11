#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int Pascal[MAXN + 1][MAXN + 1];
void PacalsTriangle()
{
    Pascal[0][0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        Pascal[i][0] = Pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
    }
}
int main()
{
    PacalsTriangle();
    int n = 0, r = 0;
    cin >> n >> r;
    cout << Pascal[n][r] << '\n';
    return 0;
}