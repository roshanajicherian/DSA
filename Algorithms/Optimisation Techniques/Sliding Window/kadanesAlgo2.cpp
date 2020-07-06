//Impletation of Kadane's Algorithm which also handles the case of negative numbers

#include <bits/stdc++.h>
using namespace std;
int kadanesAlgo(vector<int> A)
{
    int maxSoFar = A[0], maxEndingHere = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        maxEndingHere = max(A[i], maxEndingHere + A[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
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