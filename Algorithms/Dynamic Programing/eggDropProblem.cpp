#include <bits/stdc++.h>
using namespace std;
int maxi(int a, int b) { return (a > b) ? a : b; }
int eggDrop(int floor, int egg)
{
    if (floor == 0 || floor == 1)
        return floor;
    if (egg == 1)
        return floor;
    int res = 0, minimumHeight = INT_MAX;
    for (int i = 1; i <= floor; i++)
    {
        res = maxi(eggDrop(floor - 1, egg - 1), eggDrop(floor - i, egg));
        if (res < minimumHeight)
            minimumHeight = res;
    }
    return minimumHeight + 1;
}
int main()
{
    int floors = 0, eggs = 0;
    cin >> floors >> eggs;
    cout << eggDrop(floors, eggs) << '\n';
    return 0;
}