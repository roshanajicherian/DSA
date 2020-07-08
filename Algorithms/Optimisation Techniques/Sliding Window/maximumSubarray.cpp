#include <bits/stdc++.h>
using namespace std;
void findMax(vector<int> A, int n, int k)
{
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        return;
    }
    int start = 0, end = k - 1, nextStart = 0, maxElement = A[k - 1];
    while (end < n)
    {
        maxElement = max(maxElement, A[start]);
        start++;
        if (start == end && start != n)
        {
            cout << maxElement << " ";
            nextStart++;
            end++;
            start = nextStart;
            if (end < n)
                maxElement = A[end];
        }
    }
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    findMax(A, n, k);
    return 0;
}