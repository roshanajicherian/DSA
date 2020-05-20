//Solution to Longest Palindromic Substring Problem of GeekForGeeks

#include <bits/stdc++.h>
using namespace std;
void findLongestPlaindromicSubstring(string A, int n)
{
    bool isPaliandrome[n][n];
    memset(isPaliandrome, false, sizeof(isPaliandrome));
    int maxPlaindromeLength = 1;
    int palindromeStirngStart = 0; //for printing the string
    //All substrings of length 1 is a palindrome
    for (int i = 0; i < n; i++)
        isPaliandrome[i][i] = true;
    //Finding out all palaindromes of lenght 2
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            isPaliandrome[i][i + 1] = true;
            palindromeStirngStart = i;
            maxPlaindromeLength = 2;
        }
    }
    //Length of the substring choosen
    for (int substringLength = 3; substringLength <= n; substringLength++)
    {
        //choosing the starting postion
        for (int start = 0; start < n - substringLength + 1; start++)
        {
            //setting the end postion
            int end = start + substringLength - 1;
            //condtion to be a plaindrome
            if (isPaliandrome[start + 1][end - 1] == true && A[start] == A[end])
            {
                isPaliandrome[start][end] = true;
                if (substringLength > maxPlaindromeLength)
                {
                    palindromeStirngStart = start;
                    maxPlaindromeLength = substringLength;
                    // maxPlaindromeLength = max(maxPlaindromeLength, substringLength);
                }
            }
        }
    }
    cout << maxPlaindromeLength << '\n';
    for (int i = palindromeStirngStart; i < palindromeStirngStart + maxPlaindromeLength; i++)
    {
        cout << A[i];
    }
    cout << '\n';
}
void solve()
{

    string A;
    cin >> A;
    int n = A.length();
    findLongestPlaindromicSubstring(A, n);
}
int main()
{
    solve();
    return 0;
}