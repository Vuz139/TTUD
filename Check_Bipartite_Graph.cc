#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> colors;

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    colors[i] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int v : graph[p])
        {
            if (colors[v] == -1)
            {
                colors[v] = 1 - colors[p];
                q.push(v);
            }
            else
            {
                if (colors[v] == colors[p])
                {

                    cout << 0;
                    exit(1);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    graph.resize(n + 1);
    colors.resize(n + 1, -1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == -1)
        {
            bfs(i);
        }
    }
    cout << 1;
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}