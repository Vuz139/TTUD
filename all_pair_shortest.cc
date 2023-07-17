#include <bits/stdc++.h>

using namespace std;

int n, m;
int gr[1001][1001];
int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                gr[i][j] = 0;
            else
                gr[i][j] = 9999;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        gr[u][v] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (gr[i][j] == INT_MAX)
                cout << 0;
            else
                cout << gr[i][j] << ' ';
        }
        cout << endl;
    }
}