#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e3 + 1;

struct node
{
    int a;
    int t;
    float m;
    node(int x, int y)
    {
        a = x;
        t = y;
        m = x * 1.0 / y;
    }
};

bool compare(const node &a, const node &b)
{
    return a.m > b.m;
}

int n, T, D;
vector<node> stations;

void solve()
{
    cin >> n >> T >> D;
    stations.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i].a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i].t;
    }
    for (int i = 0; i < n; i++)
    {
        stations[i].m = stations[i].a * 1.0 / stations[i].t;
    }
    vector<node> dp(n);
    int visited[n];
    int curr_max_d = 0;
    for (int i = 1; i < D; i++)
    {
        if (stations[curr_max_d].m < stations[i].m)
        {
            curr_max_d = i;
        }
    }
    visited[curr_max_d] = 1;
    dp[]

        for (int i = 1; i < D; i++)
    {
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}