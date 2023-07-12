#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e5 + 1;

int n;
int d[MAX_];
int p[MAX_];
vector<double> pd;

void greedy()
{
}
bool compare(double &x, double &y)
{
    return x > y;
}

void solve()
{
    cin >> n;
    pd.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        pd[i] = p[i] * 1.0 / d[i];
    }
    sort(pd.begin(), pd.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << pd[i] << ' ';
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}