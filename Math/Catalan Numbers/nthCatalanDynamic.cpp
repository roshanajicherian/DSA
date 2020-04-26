#include <bits/stdc++.h>
using namespace std;
int catalan(int n)
{
    int catlanDP[n + 1];
    catlanDP[0] = catlanDP[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catlanDP[i] = 0;
        for (int j = 0; j < i; j++)
            catlanDP[i] += catlanDP[j] * catlanDP[i - j - 1];
    }
    return catlanDP[n];
}
int main()
{
    cout << catalan(9) << '\n';
    return 0;
}