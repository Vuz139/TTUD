#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> int_pair;
int n;
vector<vector<pair<int, int>>> g;
vector<int> d;
vector<int> parent;
void bfs(int node)
{
    d[node] = 0;

    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int_pair pp : g[top])
        {
            int x = pp.first;

            if (d[x] > 0)
            {
                // if (parent[top] == x)
                // {
                //     // cout << "FALSE" << endl;
                continue;
                // }
            }
            int w = pp.second;
            q.push(x);
            d[x] = d[top] + w;
            parent[x] = top;
        }
    }
}

int findMax()
{
    int u = 0;
    int max_ = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max_ < d[i])
        {
            max_ = d[i];
            u = i;
        }
    }
    return u;
}

void init()
{
    fill(d.begin(), d.end(), 0);
    fill(parent.begin(), parent.end(), -1);
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    d.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    int u, v, w;

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    bfs(1);
    int uu = findMax();
    init();
    bfs(uu);
    uu = findMax();
    cout << d[uu];
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
    return 1;
}