//Solution to the egg dropping problem (recursive)
#include <bits/stdc++.h>
using namespace std;
int findMinTries(int noOfEggs, int noOfFloor)
{
    //if the number of Floors is 1 then the atlest one drop is reqauired.
    //if the number of floors is 0 then no drops are required
    if (noOfFloor == 1 || noOfFloor == 0)
        return noOfFloor;
    //if only one egg is left then try with every possible
    //floor to find out where exactly the egg breaks
    if (noOfEggs == 1)
        return noOfFloor;
    int minimumHeight = INT_MAX;
    int res = 0,i;
    //Perform the calculation for each floor
    for (i = 1; i <= noOfFloor; i++)
    {
        res = max(findMinTries(noOfEggs - 1, noOfFloor - 1), findMinTries(noOfEggs, noOfFloor - i));
        if (res < minimumHeight)
            minimumHeight = res;
    }
    //the 1 is to account for the current floor
    return minimumHeight + 1;
}
int main()
{
    int noOfFloor = 10, noOfEggs = 2;
    //cin >> noOfEggs >> noOfFloor;
    cout << findMinTries(noOfEggs, noOfFloor) << '\n';
    return 0;
}