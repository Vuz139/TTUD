#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> gr;
vector<vector<int>> transposed_gr;
stack<int> st;
vector<bool> visited;
void DFSUtil(int node)
{
    visited[node] = true;
    for (int v : gr[node])
    {
        if (!visited[v])
        {
            DFSUtil(v);
        }
    }
    st.push(node);
}
void DFSUtil2(int node)
{
    visited[node] = true;
    for (int v : transposed_gr[node])
    {
        if (!visited[v])
        {
            DFSUtil2(v);
        }
    }
}
int main()
{
    // freopen("input.inp", "r", stdin);
    cin >> n >> m;
    gr.resize(n + 1);
    transposed_gr.resize(n + 1);
    visited.resize(n + 1, false);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        transposed_gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i);
        }
    }
    fill(visited.begin(), visited.end(), false);
    int tplt = 0;
    while (!st.empty())
    {
        int topp = st.top();
        st.pop();
        if (!visited[topp])
        {
            DFSUtil2(topp);
            tplt++;
        }
    }
    cout << tplt;
}