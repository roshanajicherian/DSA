#include <bits/stdc++.h>
using namespace std;
bool zeroSum(vector<int> A)
{
    int n = A.size();
    unordered_set<int> S;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += A[i];
        if (prefixSum == 0 || S.find(prefixSum) != S.end())
            return true;
        S.insert(prefixSum);
    }
    return false;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A)
        cin >> i;
    if (zeroSum(A))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}