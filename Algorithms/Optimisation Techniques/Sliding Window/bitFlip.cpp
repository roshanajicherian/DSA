//Naive soltion to the bit flip problem
#include <bits/stdc++.h>
using namespace std;
int bitFlip(vector<int> A)
{
    int intialZeroCount = 0, countOnes = 0, countZeroes = 0, maxDiff = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            intialZeroCount++;
        countOnes = 0, countZeroes = 0;
        for (int j = i; j < A.size(); j++)
        {
            if (A[j] == 1)
                countOnes++;
            else
                countZeroes++;
            maxDiff = max(maxDiff, countOnes - countZeroes);
        }
    }
    return intialZeroCount + maxDiff;
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