//recursive solution to Optimal Binary Search Tree Problem on GFG
#include <bits/stdc++.h>
using namespace std;
int findSum(int start, int end, vector<int> freq)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += freq[i];
    return sum;
}
int optimalBinarySearchTree(vector<int> freq, int start, int end)
{

    int minimumCost = INT_MAX;
    if (start > end)
        return 0;
    //if a single node is only present
    if (start == end)
        return freq[start];
    //finding out the sum of the freqenncies
    int sum = findSum(start, end, freq);
    for (int rootNode = start; rootNode <= end; rootNode++)
    {
        //left subtree+right subtree
        int cost = optimalBinarySearchTree(freq, 0, rootNode - 1) +
                   optimalBinarySearchTree(freq, rootNode + 1, end);
        minimumCost = min(minimumCost, cost);
    }
    return minimumCost + sum;
}
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    vector<int> freq(n);
    //Inputing the keys and the frequency
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    cout << optimalBinarySearchTree(freq, 0, n - 1) << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}