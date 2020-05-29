#include <bits/stdc++.h>
using namespace std;
int findSquareRoot(int x)
{
    if (x == 0 || x == 1)
        return x;
    int low = 0, high = x;
    int ans = 0; //variable to store the sqrt when there is no perfect sqaure
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    int x = 0;
    cin >> x;
    cout << findSquareRoot(x) << '\n';
    return 0;
}