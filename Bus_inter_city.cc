#include <bits/stdc++.h>

using namespace std;
struct state
{
    int cost;
    int v;
    int d;

    state(int c, int vv, int dd)
    {
        cost = c;
        v = vv;
        d = dd;
    }
};
vector<vector<int>> graph;
int minCost = INT_MAX;
vector<int> C, D;
int n, m;
vector<int> visited;

void bfs()
{
    queue<state> q;
    q.push(state(C[1], 1, D[1]));
    visited[1] = 1;
    while (!q.empty())
    {

        state st = q.front();
        state currState(0, 0, 0);
        int currentV = st.v;
        q.pop();
        if (st.d == 0)
        {
            currState.cost = st.cost + C[currentV];
            currState.d = D[currentV];
        }
        else
        {
            currState.cost = st.cost;
            currState.d = st.d - 1;
        }
        for (int v : graph[currentV])
        {
            if (visited[v] == 0)
            {
                if (v == n)
                {
                    minCost = min(minCost, currState.cost);
                }
                else
                {
                    visited[v] = 1;
                    currState.v = v;
                    q.push(currState);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    graph.resize(n + 1);
    C.resize(n + 1);
    D.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i] >> D[i];
    }
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs();
    cout << minCost;
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}