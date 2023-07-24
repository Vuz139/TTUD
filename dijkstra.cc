#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

int n, m;
vector<vector<iPair>> edges;
vector<int> dist;
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

void dijkstra(int src)
{
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (iPair pp : edges[u])
        {
            int v = pp.first;
            int w_ = pp.second;

            if (dist[v] > dist[u] + w_)
            {
                dist[v] = dist[u] + w_;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    edges.resize(n + 1);
    dist.resize(n + 1, INT_MAX);
    int u_, v_, w_;
    for (int i = 0; i < m; i++)
    {
        cin >> u_ >> v_ >> w_;
        edges[u_].push_back(make_pair(v_, w_));
    }

    int src, target;
    cin >> src >> target;
    dijkstra(src);
    cout << dist[target];
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}