#include <bits/stdc++.h>
using namespace std;
vector<int> uglyNumber;
void init()
{
    //At each iteration find the minimum possible mutliple of 2,3,5 and include that in the result.
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleof2 = 2, nextMultipleof3 = 3, nextMultipleof5 = 5;
    uglyNumber.push_back(1);
    for (int i = 1; i <= 150; i++)
    {
        int nextMultiple = min(nextMultipleof2, min(nextMultipleof3, nextMultipleof5));
        uglyNumber.push_back(nextMultiple);
        if (nextMultiple == nextMultipleof2)
        {
            i2++;
            nextMultipleof2 = 2 * uglyNumber[i2];
        }
        if (nextMultiple == nextMultipleof3)
        {
            i3++;
            nextMultipleof3 = 3 * uglyNumber[i3];
        }
        if (nextMultiple == nextMultipleof5)
        {
            i5++;
            nextMultipleof5 = 5 * uglyNumber[i5];
        }
    }
}
void solve()
{
    int n = 0;
    cin >> n;
    n--;
    cout << uglyNumber[n] << '\n';
}
int main()
{
    init();
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}