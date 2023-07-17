#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> gr;
int visited[100000];
void dfs(int node)
{
    visited[node] = 1;
    cout << node << ' ';
    for (int v : gr[node])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    gr.resize(n + 1);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}