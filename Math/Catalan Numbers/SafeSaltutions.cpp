//Safe Salutions problem from UVA online judge
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int catlanDP[MAXN];
void init(int n)
{
    catlanDP[0] = catlanDP[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catlanDP[i] = 0;
        int res = 0;
        for (int j = 0; j < i; j++)
        {
            res = (catlanDP[j] * catlanDP[i - j - 1]);
            catlanDP[i] = (catlanDP[i] + res);
        }
    }
}
int main()
{
    init(1000);
    int n = 0;
    cin >> n;
    cout << catlanDP[n] << '\n';
    return 0;
}