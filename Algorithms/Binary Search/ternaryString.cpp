#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool functionCalc(int k, string S)
{
    int frequencyArray[4];
    memset(frequencyArray, 0, sizeof(frequencyArray));
    for (int i = 0; i < k - 1; i++)
    {
        int x = S[i] - '0';
        frequencyArray[x]++;
    }
    for (int i = k - 1; i < S.length(); i++)
    {
        int x = S[i] - '0';
        frequencyArray[x]++;
        if ((frequencyArray[1] > 0) && (frequencyArray[2] > 0) && (frequencyArray[3] > 0))
            return true;
        x = S[i - k + 1] - '0';
        frequencyArray[x]--;
    }
    return false;
}
void solve()
{
    string S;
    cin >> S;
    int low = 3;
    int minimumSubArrayLength = INT_MAX;
    int high = S.length();
    //Here the function is a boolen function which returns wheather the string contains 1,2 and 3. This is
    //mnontomic function and strictly increasig function
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (functionCalc(mid, S))
        {
            minimumSubArrayLength = min(minimumSubArrayLength, mid); //check here
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if (minimumSubArrayLength == INT_MAX)
        cout << 0 << '\n';
    else
        cout << minimumSubArrayLength << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
}