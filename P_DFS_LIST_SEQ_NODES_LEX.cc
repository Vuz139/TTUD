// Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
// Write a program that compute the sequence of nodes visited using a DFS algorithm (the nodes are considered in a lexicographic order)

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<set<int>> edges;
vector<int> visited;

void dfs(int v)
{
    cout << v << " ";
    visited[v] = 1;
    for (int u : edges[v])
    {
        if (visited[u] == 0)
        {
            dfs(u);
        }
    }
}

void solve()
{
    cin >> n >> m;
    edges.resize(n + 1);
    visited.resize(n + 1, 0);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;
        edges[v].insert(u);
        edges[u].insert(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}