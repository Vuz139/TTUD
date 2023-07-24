#include <bits/stdc++.h>

using namespace std;

vector<int> _list;
int n, M;
int Q;

void solve()
{
    cin >> n >> M;
    Q = 0;
    _list.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> _list[i];
    }

    vector<bool> check(M, false);

    for (int v : _list)
    {
        if (check[M - v])
        {
            Q++;
        }
        check[v] = true;
    }
    cout << Q << endl;
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}