//Find out the minimum cuts required to partititon a string so that the resulting strings formed are palindromes
#include <bits/stdc++.h>
using namespace std;
int solve()
{
    string S;
    cin >> S;
    //Whenever there are partitions/cuts it is similar to matrix chain multiplication problem
    //Base case if there is only one character in the string then it is a palindrome
    int n = S.length();
    int DP[n][n];
    bool isPalindrome[n][n];
    for (int i = 0; i < n; i++)
    {
        DP[i][i] = 0;
        isPalindrome[i][i] = true;
    }
    //Chosing the length of the subsequence
    for (int subsequnceLength = 2; subsequnceLength <= n; subsequnceLength++)
    {
        //Chosing the starting positon
        for (int start = 0; start < n - subsequnceLength + 1; start++)
        {
            //Ending position
            int end = start + subsequnceLength - 1;
            if (subsequnceLength == 2)
                //if the length is 2 check the corner character to confirm it is a palindrome
                isPalindrome[start][end] = (S[start] == S[end]);
            else
                isPalindrome[start][end] = (S[start] == S[end]) && (isPalindrome[start + 1][end - 1]);
            //making the cost of partitioning of all palindromes zero
            if (isPalindrome[start][end] == true)
                DP[start][end] = 0;
            else
            {
                //finding out the minimum possible cuts
                DP[start][end] = INT_MAX;
                for (int k = start; k <= end - 1; k++)
                    DP[start][end] = min(DP[start][k] + DP[k + 1][end] + 1, DP[start][end]);
            }
        }
    }
    return DP[0][n - 1];
}
int main()
{
    cout << solve() << '\n';
    return 0;
}