
//Implentation of Kadane's Alogorithm to find the largest sum subsequence
//!!Does not handle the case when all the numbers in the array are negative
#include <bits/stdc++.h>
using namespace std;
int kadanesAlgo(vector<int> A)
{
    int maxSoFar = 0, maxEndingHere = 0;
    for (int i = 0; i < A.size(); i++)
    {
        maxEndingHere += A[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        else if (maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << kadanesAlgo(A) << '\n';
    return 0;
}