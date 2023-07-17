#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> int_pair;
int n;
vector<vector<pair<int, int>>> g;

int dfs(int node, int parent)
{

    int max_len = 0;
    for (int_pair v : g[node])
    {
        if (v.first != parent)
        {
            int w = v.second + dfs(v.first, node);
            max_len = max(w, max_len);
        }
    }
    longest_at[node] = max_len;
    return max_len;
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    int u, v, w;

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    int max_dis = -1;

    max_dis = max(max_dis, dfs(i, -1));

    cout << max_dis << endl;
}
int main()
{
    solve();
    return 1;
}