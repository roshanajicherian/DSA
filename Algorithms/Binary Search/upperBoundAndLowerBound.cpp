//Testing upper bond and lower bound functions
#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> A)
{
    for (auto i : A)
        cout << i << ' ';
    cout << '\n';
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Before sorting : ";
    printVector(A);
    sort(A.begin(), A.end());
    cout << "After sorting : ";
    printVector(A);
    int x = 0;
    cout << "Enter x : ";
    cin >> x;
    cout << "Lower bound :" << lower_bound(A.begin(), A.end(), x) - A.begin() << '\n';                                  //lower bound returns the positon of the first element >=x
    cout << "Upper bound :" << upper_bound(A.begin(), A.end(), x) - A.begin() << '\n';                                  //upper bound return the postion of the frist element >x
    cout << "No of occurence of x " << upper_bound(A.begin(), A.end(), x) - lower_bound(A.begin(), A.end(), x) << '\n'; // No of occurence of a particular element
}