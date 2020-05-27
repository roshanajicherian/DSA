#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int titlingFib[MAXN + 1];
void init()
{
    titlingFib[1] = 1;
    titlingFib[2] = 2;
    for (int i = 3; i <= MAXN; i++)
        titlingFib[i] = titlingFib[i - 1] + titlingFib[i - 2];
}
int main()
{
    init();
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        cout << titlingFib[n] << '\n';
    }

    return 0;
}