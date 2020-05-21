#include <bits/stdc++.h>
using namespace std;
#define MAX 10000.0
double dist(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt(((p1.first - p2.first) * (p1.first - p2.first)) + ((p1.second - p2.second) * (p1.second - p2.second)));
}
double cst(int i, int j, int k, vector<pair<double, double>> Points)
{
    pair<double, double> p1 = {Points[i].first, Points[i].second};
    pair<double, double> p2 = {Points[j].first, Points[j].second};
    pair<double, double> p3 = {Points[k].first, Points[k].second};
    return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}
void findMinimumTriangultaions(vector<pair<double, double>> Points)
{
    int n = Points.size();
    if (n < 3)
    {
        cout << 0;
        return;
    }
    double DP[n][n];
    for (int sequenceLength = 0; sequenceLength < n; sequenceLength++)
    {
        for (int start = 0, start = sequenceLength; end < n; start++, end++)
        {
            if (end < start + 2)
                DP[start][end] = 0.0;
            else
            {
                DP[start][end] = MAX;
                for (int k = start + 1; k < end; k++)
                {
                    double cost = DP[start][k] + DP[k][end] + cst(start, end, k, Points);
                    DP[start][end] = min(DP[start][end], cost);
                }
            }
        }
    }
    cout << DP[0][n - 1] << '\n';
}
int main()
{
    vector<pair<double, double>> Points;
    Points = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    findMinimumTriangultaions(Points);
    return 0;
}