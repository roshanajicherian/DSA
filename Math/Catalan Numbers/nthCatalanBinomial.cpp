#include <bits/stdc++.h>
using namespace std;
//Function to find nCr
int findBinomialCoeff(int n, int r)
{
    if (r > n - r)
        r = n - r;
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int findCatalan(int n)
{
    //nth catlan numer = (2nCn)/(n+1)
    int numerator = findBinomialCoeff(2 * n, n);
    int denominator = n + 1;
    return numerator / denominator;
}
int main()
{
    cout << findCatalan(9) << '\n';
    return 0;
}