//Solution to the 0-1 Kanpscack problem using recursion
//Idea: At every step I have two poosiblites-
//Either to include the ith weight or to nor include it
//if it is included the reducse the total weight
//if not included decrement the weight under considerartion
#include <bits/stdc++.h>
using namespace std;
int knapsack(int weightOfObjects[], int profit[], int totalWeight, int endIndex)
{
    if (endIndex == 0 || totalWeight == 0)
        return 0;
    if (totalWeight - weightOfObjects[endIndex - 1] < 0)
        return knapsack(weightOfObjects, profit, totalWeight, endIndex - 1);
    return max(profit[endIndex - 1] +
                   knapsack(weightOfObjects, profit, totalWeight - weightOfObjects[endIndex-1], endIndex - 1),
               knapsack(weightOfObjects, profit, totalWeight, endIndex - 1));
}
int main()
{
    int weightOfObjects[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int W = 50;
    cout << knapsack(weightOfObjects, profit, W, 3) << '\n';
    return 0;
}