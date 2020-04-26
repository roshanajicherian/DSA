#include <bits/stdtr1c++.h>
using namespace std;
int findLis(int A[], int n)
{
    int lisArray[n];
    int maximumLISLength = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        lisArray[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && lisArray[j] + 1 > lisArray[i])
                lisArray[i] = lisArray[j] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        maximumLISLength = max(maximumLISLength, lisArray[i]);
    return maximumLISLength;
}

int main()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << findLis(A, n) << '\n';
    return 0;
}