#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> parent;
vector<int> rank_;
int find(int u)
{
    if (parent[u] != u)
        parent[u] = find(parent[u]);

    return parent[u];
}

// Union of two sets by rank
void merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (rank_[u] > rank_[v])
        parent[v] = u;
    else
        parent[u] = v;

    if (rank_[u] == rank_[v])
        ++rank_[v];
}
void init()
{
    parent.resize(n + 1);
    rank_.resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
pair<int, int> x[21];
int y[21];
vector<pair<int, int>> edges;
bool solution()
{

    init();
    for (int i = 0; i < n - 1; i++)
    {
        auto edge = x[i];
        int u = find(edge.first);
        int v = find(edge.second);
        if (u != v)
            merge(u, v);
        else
        {
            return false;
        }
    }
    return true;
}
int numbers_of_sptree = 0;
void TRY(int i)
{
    for (int j = y[i - 1] + 1; j < m; j++)
    {
        x[i] = edges[j];
        y[i] = j;
        if (i == n - 2)
        {
            if (solution())
            {
                numbers_of_sptree++;
            }
        }
        else
        {
            TRY(i + 1);
        }
    }
}
int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges.push_back({u, v});
    }
    for (int i = 0; i < m - n + 2; i++)
    {
        x[0] = edges[i];
        y[0] = i;
        TRY(1);
    }
    cout << numbers_of_sptree << endl;
}