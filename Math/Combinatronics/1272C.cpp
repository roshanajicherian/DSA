#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    string S;
    cin >> S;
    set<char> avilableKeys;
    while (k--)
    {
        char temp;
        cin >> temp;
        avilableKeys.insert(temp);
    }
    lli totalSubstring = (n * (n + 1)) / 2;
    lli dpArray[n];
    lli unavialbleOccuredIndex = -1;

    for (lli i = 0; i < n; i++)
    {
        bool anotherKey = false;
        if (unavialbleOccuredIndex == -1 || i > unavialbleOccuredIndex)
        {
            for (lli j = i; j < n; j++)
            {
                if (avilableKeys.find(S[j]) == avilableKeys.end())
                {
                    anotherKey = true;
                    unavialbleOccuredIndex = j;
                    break;
                }
                else
                    unavialbleOccuredIndex = 0;
            }
            if (anotherKey)
                dpArray[i] = n - unavialbleOccuredIndex;
            else
                dpArray[i] = 0;
        }
        else
            dpArray[i] = dpArray[i - 1];
    }
    lli removedValues = 0;
    for (lli i = 0; i < n; i++)
    {
        removedValues += dpArray[i];
    }
    cout << totalSubstring - removedValues << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}