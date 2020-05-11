#include <bits/stdc++.h>
using namespace std;
#define v 4
#define INF INT_MAX
void FloydWarshall(int graph[][v])
{
    int shortestPath[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            shortestPath[i][j] = graph[i][j];
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (shortestPath[i][k] + shortestPath[k][j] < shortestPath[i][j])
                    shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (shortestPath[i][j] == INF)
                cout << "INF ";
            else
                cout << shortestPath[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    int graph[v][v] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    FloydWarshall(graph);
    return 0;
}