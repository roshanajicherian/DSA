#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    int letterCount[26];
    memset(letterCount, 0, sizeof(letterCount));
    while (n--)
    {
        string temp;
        cin >> temp;
        letterCount[temp[0] - 'a']++;
    }
    int pairsPossible = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letterCount[i] > 2)
        {
            int temp = letterCount[i] - 2;
            int leftCount = 1, rightCount = 1;
            while (temp)
            {
                leftCount++;
                temp--;
                if (temp)
                {
                    rightCount++;
                    temp--;
                }
            }
            pairsPossible += ((leftCount) * (leftCount - 1)) / 2;
            pairsPossible += ((rightCount) * (rightCount - 1)) / 2;
        }
    }
    cout << pairsPossible << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}