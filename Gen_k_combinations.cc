#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[10000];
void solution()
{
    for (int i = 0; i < m; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
}

void TRY(int i)
{
    for (int j = x[i - 1] + 1; j <= n; j++)
    {

        x[i] = j;
        if (i == m - 1)
        {
            solution();
        }
        else
        {
            TRY(i + 1);
        }
    }
}

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n - m + 1; i++)
    {
        x[0] = i;
        TRY(1);
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}