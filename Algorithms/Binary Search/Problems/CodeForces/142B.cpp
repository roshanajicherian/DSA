#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool isPrime(lli n)
{
    if(n <= 1) return false;
    if (n <= 3)
        return true;
    if ((n % 2 == 0) || (n % 3 == 0))
        return false;
    for (lli i = 5; i * i <= n; i += 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }
    return true;
}
vector<bool> findTPrimes(vector<lli> A)
{
    lli n=A.size();
    vector<bool> result(n);
    for (lli i = 0; i < n; i++)
    {
        lli number = A[i];
        lli squareRoot = sqrt(number);
        if (squareRoot * squareRoot == number)
        {
            if (isPrime(squareRoot))
                result[i] = true;
            else
                result[i] = false;
        }
        else
            result[i] = false;
    }
    return result;
}
int main()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    for (auto &i : A)
        cin >> i;
    vector<bool> result = findTPrimes(A);
    for (auto i : result)
    {
        if (i == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
