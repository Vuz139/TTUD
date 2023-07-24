#include <bits/stdc++.h>

using namespace std;
const int max_ = 1e4 + 1;
int V, m;
int s, t;
int graph[max_][max_];
vector<int> parent;

bool BFS()
{
    vector<bool> visited(V + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= V; v++)
        {
            if (!visited[v] && graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int maxFlow()
{

    int maxFlow = 0;

    while (BFS())
    {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {

            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main()
{
    // freopen("input.inp", "r", stdin);
    // freopen("output.oup", "w", stdout);
    cin >> V >> m;
    parent.resize(V + 1, -1);
    cin >> s >> t;
    int u, v, capa;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> capa;
        graph[u][v] = capa;
    }
    cout << maxFlow();
}