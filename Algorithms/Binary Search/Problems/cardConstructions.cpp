// Solution to Card Construction Problem of CodeForce Round 639

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 1000000
vector<lli> cardsRequired(MAX + 1);
void solve()
{
    lli n = 0;
    cin >> n;
    lli pyramidsPossible = 0;
    while (n > 0)
    {
        lli cardIndex = lower_bound(cardsRequired.begin(), cardsRequired.end(), n) - cardsRequired.begin();
        if (cardsRequired[cardIndex] == n)
            n = 0;
        else
        {
            if (cardIndex-1 == 0)
                break;
            n -= cardsRequired[cardIndex - 1];
        }
        pyramidsPossible++;
    }
    cout << pyramidsPossible << '\n';
}
void preCompute()
{
    cardsRequired[0] = 0;
    cardsRequired[1] = 2;
    for (lli i = 2; i <= MAX; i++)
        cardsRequired[i] = cardsRequired[i - 1] + ((2 * i) + (i - 1));
    // for (lli i = 0; i <= 100; i++)
    //     cout << cardsRequired[i] << ' ';
    // cout << '\n';
}
int main()
{
    preCompute();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}