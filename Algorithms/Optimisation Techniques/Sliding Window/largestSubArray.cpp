#include <bits/stdc++.h>
using namespace std;
int findLargest(vector<int> A)
{
    int n = A.size();
    int maxLength = -1;
    int startIndex = 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = ((A[0] == 1) ? 1 : -1);
    int maxPrefix = A[0], minPrefix = A[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + ((A[i] == 1) ? 1 : -1);
        maxPrefix = max(maxPrefix, prefixSum[i]);
        minPrefix = min(minPrefix, prefixSum[i]);
    }
    vector<int> hashMap(maxPrefix - minPrefix + 1,-1);
    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] == 0)
        {
            maxLength = i+1;
            startIndex = 0;
        }
        if (hashMap[prefixSum[i] - minPrefix] == -1)
            hashMap[prefixSum[i] - minPrefix] = i;
        else if (i - hashMap[prefixSum[i] - minPrefix] > maxLength)
        {
            maxLength = i - hashMap[prefixSum[i] - minPrefix];
            startIndex = hashMap[prefixSum[i] - minPrefix] + 1;
        }
    }
    if (maxLength == -1)
        return 0;
    else
        return maxLength;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << findLargest(A);
    return 0;
}