#include <bits/stdc++.h>

using namespace std;

const int maxN = 110;

int n, m;
int visit[maxN];
int d[maxN];
int start_[maxN];
int total_time = 0;
vector<int> g[maxN];
vector<int> p[maxN];
vector<int> topo;

void dfs(int u)
{
    visit[u] = 1;
    for (auto v : g[u])
    {
        if (!visit[v])
        {

            dfs(v);
        }
    }
    topo.push_back(u);
    visit[u] = 2;
}

main()
{
    // freopen("input.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        p[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visit[i])
            dfs(i);
    }

    reverse(topo.begin(), topo.end());
    for (int v : topo)
    {
        if (!p[v].empty())
        {
            int max_ = -1;
            for (int u : p[v])
            {
                max_ = max(max_, start_[u] + d[u]);
            }
            start_[v] = max_;
        }
        else
        {
            start_[v] = 0;
        }
    }
    int max__ = -1;
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max__ < start_[i])
        {
            max__ = start_[i];
            id = i;
        }
    }
    max__ += d[id];
    cout << max__;
}