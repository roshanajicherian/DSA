#include <bits/stdc++.h>
using namespace std;
void simpleSieve(vector<int> &primes, int segmentLength)
{
    bool primesMark[segmentLength + 1];
    memset(primesMark, true, sizeof(primesMark));
    for (int i = 2; i * i <= segmentLength; i++)
    {
        if (primesMark[i] == true)
        {
            for (int j = i * 2; j < segmentLength; j += i)
                primesMark[j] = false;
        }
    }
    for (int i = 2; i < segmentLength; i++)
    {
        if (primesMark[i] == true)
        {
            primes.push_back(i);
            cout << i << ' ';
        }
    }
}
void findPrimes(int n)
{
    vector<int> primes;
    int segmentLength = floor(sqrt(n)) + 1;
    simpleSieve(primes, segmentLength);
    int lowerSegmentLimit = segmentLength, higherSegmentLimit = 2 * segmentLength;
    while (lowerSegmentLimit < n)
    {
        if (higherSegmentLimit > n)
            higherSegmentLimit = n;
        bool isPrime[segmentLength + 1];
        memset(isPrime, true, sizeof(isPrime));
        for (int i = 0; i < primes.size(); i++)
        {
            int miniumDivisible = floor(lowerSegmentLimit / primes[i]) * primes[i];
            if (miniumDivisible < lowerSegmentLimit)
                miniumDivisible += primes[i];
            for (int p = miniumDivisible; p < higherSegmentLimit; p += primes[i])
                isPrime[p - lowerSegmentLimit] = false;
        }
        for (int i = lowerSegmentLimit; i < higherSegmentLimit; i++)
        {
            if (isPrime[i - lowerSegmentLimit] == true)
                cout << i << ' ';
        }
        lowerSegmentLimit += segmentLength;
        higherSegmentLimit += segmentLength;
    }
    cout << '\n';
}
int main()
{
    int n = 0;
    cin >> n;
    findPrimes(n);
    return 0;
}