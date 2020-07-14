#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string S;
    cin >> S;
    int n = S.length();
    vector<int> conditionMet(n, 0);
    for (int i = 1; i < n; i++)
        if (S[i] == S[i - 1])
            conditionMet[i] = conditionMet[i - 1] + 1;
        else
            conditionMet[i] = conditionMet[i - 1];
    for (int i = 0; i < n; i++)
        cout << conditionMet[i] << ' ';
    cout << '\n';
    int m = 0;
    cin >> m;
    while (m--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        l--, r--;
        cout << conditionMet[r] - conditionMet[l] << '\n';
    }
}
int main()
{

    solve();
    return 0;
}