#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> int_pair;
int n;
vector<vector<int>> w;
vector<vector<int>> gr;

void dfs(int i, int node, int p)
{
    for (int v : w[node])
    {
        if (p != v && !gr[i][v])
        {
            gr[i][v] = gr[node][v] + gr[i][node];
            gr[v][i] = gr[i][v];
            dfs(i, v, node);
        }
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    cin >> n;
    gr.resize(n + 1);
    w.resize(n + 1);
    int u, v, m;
    for (int i = 0; i <= n; i++)
    {
        gr[i].resize(n + 1, 0);
    }
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> m;
        gr[u][v] = m;
        gr[v][u] = m;
        w[u].push_back(v);
        w[v].push_back(u);
    }

    int sum;
    int max_sum = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int v : w[i])
        {
            dfs(i, v, i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {

            sum += gr[i][j];
        }

        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;
}
