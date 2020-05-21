//Solution to binary string with no consecutive 1s from GFG
#include <bits/stdc++.h>
using namespace std;
void findBinaryStrings(int n)
{
    int endingWith1[n + 1], endingWith0[n + 1];
    endingWith1[1] = endingWith0[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        endingWith0[i] = endingWith0[i - 1] + endingWith1[i - 1];
        endingWith1[i] = endingWith0[i - 1];
    }
    cout << endingWith1[n] + endingWith0[n] << '\n';
}
int main()
{
    int n = 0;
    cin >> n;
    findBinaryStrings(n);
    return 0;
}