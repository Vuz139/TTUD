#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> visited;
vector<int> x;

void solution()
{
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
}

void TRY(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            visited[j] = 1;
            x[i] = j;
            if (i == n - 1)
            {
                solution();
            }
            else
            {
                TRY(i + 1);
            }
            visited[j] = 0;
        }
    }
}

void solve()
{
    cin >> n;
    x.resize(n + 1);
    visited.resize(n + 1, 0);
    TRY(0);
}
int main()
{
    solve();
}