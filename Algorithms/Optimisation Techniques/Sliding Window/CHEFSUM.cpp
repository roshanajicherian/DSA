#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    // PrefixSum(i)+SuffixSum(i) must be minimum
    // ==> (A[0]+A[1]+.....+A[i-1]+A[i])+(A[i]+A[i+1]+....+A[n]) must be minimum
    // ==> (A[0]+A[1]+...++A[i]+A[i+1]+...+A[n])+ A[i] must be minimum
    // ==> Sum of the elements of the array + A[i] must be minimum
    // ==> Since Sum of the elements of the array is a constant ==> A[i] must be minimum
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    lli minimumElement = INT_MAX, minimumIndex = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] < minimumElement)
        {
            minimumElement = A[i];
            minimumIndex = i;
        }
    }
    cout << minimumIndex + 1 << '\n'; // 1 based indexing required in the result
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}