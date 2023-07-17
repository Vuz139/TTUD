#include <bits/stdc++.h>

using namespace std;
int T;
int n, m;
vector<vector<int>> gr;
vector<int> x;
vector<int> visited;
int solution;

void TRY(int i)
{

    for (int j : gr[x[i - 1]])
    {
        if (!visited[j])
        {
            visited[j] = 1;
            x[i] = j;
            if (i == n - 1)
            {
                for (int v : gr[j])
                {
                    if (v == x[0])
                        solution = 1;
                }
            }
            else
            {
                if (!solution)
                    TRY(i + 1);
            }
            visited[j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.inp", "r", stdin);
    cin >> T;
    while (T > 0)
    {
        cin >> n >> m;
        x.resize(n + 1);
        visited.resize(n + 1, 0);
        gr.resize(n + 1);
        solution = 0;
        int v, u;
        for (int i = 0; i < m; i++)
        {
            cin >> v >> u;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!solution)
            {
                x[0] = i;
                TRY(1);
            }
        }
        if (solution)
            cout << 1 << endl;
        else
        {
            cout << 0 << endl;
        }
        gr.clear();
        x.clear();
        visited.clear();
        T--;
    }
}