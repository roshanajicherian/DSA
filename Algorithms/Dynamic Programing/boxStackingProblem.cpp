//Solution to Box Stacking problem
//Soltuion from TechieDelight
#include <bits/stdc++.h>
using namespace std;
struct Box
{
    int length, width, height;
};
vector<Box> findRotations(vector<Box> boxes)
{
    vector<Box> rotations;
    for (auto i : boxes)
    {
        rotations.push_back({i.length, i.width, i.height});
        rotations.push_back({max(i.length, i.height), min(i.length, i.height), i.width});
        rotations.push_back({max(i.width, i.height), min(i.width, i.height), i.length});
    }
    return rotations;
}
bool compare(Box x, Box y)
{
    int baseArea1 = x.length * x.width;
    int baseArea2 = y.length * y.width;
    return baseArea1 > baseArea2;
}
void solve(vector<Box> boxes)
{
    //STEP 1-> Find out all possible rotations
    vector<Box> rotations = findRotations(boxes);
    //STEP 2-> Sort the rotations in descending order of base area
    sort(rotations.begin(), rotations.end(), compare);
    vector<int> DP(rotations.size());
    //Steps similar to LIS problem
    //Instead of intializing the resultant array with the heights the loops have been modified to obtain the same reuslt
    for (int i = 0; i < rotations.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rotations[i].length < rotations[j].length && rotations[i].width < rotations[j].width)
                DP[i] = max(DP[i], DP[j]);
        }
        DP[i] += rotations[i].height;
    }
    int max = *max_element(DP.begin(), DP.end());
    cout << max << '\n';
}
int main()
{
    vector<Box> boxes{
        {4, 2, 5},
        {3, 1, 6},
        {3, 2, 1},
        {6, 3, 8}};
    solve(boxes);
    return 0;
}