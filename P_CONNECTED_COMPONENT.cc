#include <bits/stdc++.h>

using namespace std;

int n, m;
int tplt = 0;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int v)
{
    for (int u : graph[v])
    {
        if (visited[u] == 0)
        {
            visited[u] = 1;
            dfs(u);
        }
    }
}

void input()
{
    cin >> n >> m;
    graph.resize(n + 1);
    int v, u;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            tplt++;
        }
    }
    cout << tplt << endl;
}

int main()
{
    // freopen("input.inp", "r", stdin);

    input();
}