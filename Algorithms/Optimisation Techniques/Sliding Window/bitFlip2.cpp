//Efficent Soltuion to the Bit Flip problem

#include <bits/stdc++.h>
using namespace std;
int bitFlip(vector<int> A)
{
    int intialZeroCount = 0, maxSoFar = 0, maxEndingHere = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            intialZeroCount++;
        int val = (A[i] == 0) ? -1 : 1;
        maxEndingHere = max(val, maxEndingHere + val);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    maxSoFar = max(0, maxSoFar);
    return intialZeroCount + maxSoFar;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << bitFlip(A) << '\n';
    return 0;
}