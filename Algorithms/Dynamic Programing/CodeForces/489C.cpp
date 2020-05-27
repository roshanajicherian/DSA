// Solution to 489C- Given Length and Sum of Digits...
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int m = 0, s = 0;
    cin >> m >> s;
    if (s == 0)
    {
        if (m == 1)
            cout << 0 << ' ' << 0 << '\n';
        else
            cout << -1 << ' ' << -1 << '\n';
        return;
    }
    string ResultMin, ResultMax;
    for (int i = 0; i < m; i++)
    {
        int ithDigit = min(9, s);
        ResultMax += (ithDigit + '0');
        s -= ithDigit;
    }
    if (s > 0)
    {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    for (int i = ResultMax.length() - 1; i >= 0; i--)
        ResultMin += ResultMax[i];
    int i = 0;
    //To correct the problem of leading zeroes
    while (ResultMin[i] == '0')
        i++;
    ResultMin[i]--, ResultMin[0]++;
    cout << ResultMin << ' ' << ResultMax << '\n';
}
int main()
{
    solve();
    return 0;
}