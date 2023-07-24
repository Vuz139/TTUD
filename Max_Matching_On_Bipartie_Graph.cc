#include <iostream>
#include <algorithm>
#include <vector>
#define fr(a, b, c) for (a = b; a <= c; a++)
#define frr(a, b, c) for (a = b; a >= c; a--)
using namespace std;
const int max_ = 1e4;
int m, n, t;
vector<int> a, b, d;
vector<vector<int>> c;

int dfs(int x)
{
    int i;
    fr(i, 1, n) if (c[x][i] && !d[i])
    {
        t = i;
        d[i] = x;
        if (!b[i] || dfs(b[i]))
            return 1;
    }
    return 0;
}

int find()
{
    int i;
    fr(i, 1, n) d[i] = 0;
    fr(i, 1, m) if (!a[i]) if (dfs(i)) return 1;
    return 0;
}

void inc()
{
    int x, y;
    while (t)
    {
        x = d[t];
        y = t;
        t = a[x];
        a[x] = y;
        b[y] = x;
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    int i, x, y, re = 0;
    a.resize(max_ + 1);
    b.resize(max_ + 1);
    d.resize(max_ + 1);
    c.resize(max_ + 1);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        c[i].resize(max_ + 1, 0);
        int size, temp;
        cin >> size;
        for (int j = 1; j <= size; j++)
        {
            cin >> temp;
            c[i][temp] = 1;
        }
    }
    while (find())
        inc();
    fr(i, 1, m) if (a[i]) re++;
    cout << re << endl;
    return 0;
}
