#include <bits/stdc++.h>
using namespace std;

const int Max = 1e6 + 1;
map<string, bool> a;
int n, m;
int exps[Max];

void cc()
{
    const int xxxxx = (256 % m);
    exps[0] = 1;
    for (int i = 1; i <= 205; i++)
    {
        exps[i] = ((exps[i - 1] % m) * xxxxx) % m;
    }
}

void compute()
{
    string a;
    cin >> a;
    int sa = a.size();
    int sum = 0;
    for (int i = 0; i <= sa; i++)
    {
        sum += (int)a[i] * exps[sa - i - 1];
        sum %= m;
    }
    cout << sum << endl;
}

void solve()
{
    cin >> n >> m;
    cc();
    while (n--)
    {
        compute();
    }
}

signed main()
{
    freopen("input.in", "r", stdin);
    solve();
}