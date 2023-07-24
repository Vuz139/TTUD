#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited(false);
vector<vector<int>> cities;
vector<int> route;
int cmin;
int f0;
int f;
int g;
void input()
{
    cin >> n;
    visited.resize(n);
    route.resize(n);
    cities.resize(n);
    cmin = INT_MAX;
    f0 = INT_MAX;
    f = 0;
    for (int i = 0; i < n; i++)
    {
        cities[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> cities[i][j];
            cmin = min(cmin, cities[i][j]);
        }
    }
}
void Try(int k)
{

    for (int v = 1; v < n; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            route[k] = v;
            f += cities[route[k - 1]][v];
            if (k == n - 1)
            {
                if (f + cities[v][0] < f0)
                {
                    f0 = f + cities[v][0];
                }
            }
            else
            {
                g = f + (n - k - 1) * cmin;
                if (g < f0)
                {
                    Try(k + 1);
                }
            }
            visited[v] = false;
            f -= cities[route[k - 1]][v];
        }
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    input();
    route[0] = 0;
    visited[0] = true;
    Try(1);
    cout << f0 << endl;

    return 0;
}