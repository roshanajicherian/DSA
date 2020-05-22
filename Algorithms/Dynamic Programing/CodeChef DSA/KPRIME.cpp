#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAXN 100000
vector<lli> primeFactorCount(MAXN + 1, 0);
void init()
{
  for (lli i = 2; i <= MAXN; i++)
  {
    if (primeFactorCount[i] == 0)
    {
      for (lli j = i; j <= MAXN; j += i)
        primeFactorCount[j]++;
    }
  }
}
void solve()
{
  lli a = 0, b = 0, k = 0;
  cin >> a >> b >> k;
  int count = 0;
  for (int i = a; i <= b; i++)
    if (primeFactorCount[i] == k)
      count++;
  cout << count << '\n';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  lli t = 0;
  cin >> t;
  while (t--)
    solve();
  return 0;
}