#include <bits/stdc++.h>
using namespace std;
int findGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1 = 0, y1 = 0;
    int g = findGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
int main()
{
    int a = 0, b = 0, x = 0, y = 0;
    cin >> a >> b;
    cout << findGCD(a, b, x, y) << '\n';
    cout << x << ' ' << y << '\n';
    return 0;
}