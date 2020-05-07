#include <bits/stdc++.h>
using namespace std;
//!CHECK LPDDynamic.cpp for explanantion
int findLPS(string A, int start, int end)
{
    if (start == end)
        return 1;
    if (end == start + 1 && A[start] == A[end])
        return 2;
    if (A[start] == A[end])
        return findLPS(A, start + 1, end - 1) + 2;
    else
        return max(findLPS(A, start, end - 1), findLPS(A, start + 1, end));
}
int main()
{
    string A;
    cin >> A;
    int n = A.length();
    cout << findLPS(A, 0, n - 1) << '\n';
    return 0;
}