#include <bits/stdc++.h>
const int MAX_ = 1e5 + 1;
using namespace std;

int n;
vector<vector<int>> tree_;
int w[MAX_];
int dp[MAX_];
int dfs(int node, int parent)
{
    if (dp[node])
        return dp[node];
    if (tree_[node].size() < 1)
    {
        return w[node];
    }
    int chose_node = w[node];
    int not_chose_node = 0;
    for (int v : tree_[node])
    {
        if (v != parent)
        {
            not_chose_node += dfs(v, node);
        }
    }
    for (int v : tree_[node])
    {
        if (v != parent)
        {
            for (int child : tree_[v])
            {
                if (child != node)
                {
                    chose_node += dfs(child, v);
                }
            }
        }
    }
    chose_node = max(chose_node, not_chose_node);
    dp[node] = chose_node;
    return chose_node;
}

int main()
{
    cin >> n;
    tree_.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree_[u].push_back(v);
        tree_[v].push_back(u);
    }
    cout << dfs(1, -1);
}