#include <bits/stdc++.h>
using namespace std;
const int MAX_ = 1e3 + 3;

int n, m;
vector<vector<int>> d;
vector<vector<int>> constraints;
int x[MAX_];
vector<int> visited;
int currentRoute = 0;

bool check(int i)
{
    if (visited[i] != 0)
        return false;
    for (int v : constraints[i])
    {
        if (visited[v] == 0)
            return false;
    }
    return true;
}

void TRY(int i)
{
    if (check(x[i]))
    {
        currentRoute += d[x[i - 1]][x[i]];

        visited[x[i]] = 1;
        if (i == n - 1)
        {
            return;
        }
        else
        {

            TRY(i + 1);
        }
    }
    else
    {
        cout << -1;
        exit(1);
    }
}

void input()
{
    cin >> n;
    d.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        d[i].resize(n + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    constraints.resize(n + 1);
    cin >> m;
    int x1, x2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> x2;
        constraints[x2].push_back(x1);
    }

    visited.resize(n + 1, 0);
    visited[x[0]] = 1;
    TRY(1);
    cout << currentRoute + d[x[n - 1]][x[0]];
}

int main()
{
    // freopen("input.inp", "r", stdin);
    input();
}