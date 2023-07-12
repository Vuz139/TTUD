#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 100;
int n, k;
int a[MAX_][MAX_];

void solve()
{
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int dp[MAX_][MAX_];
    int c_max = -1;
    for (int i = 0; i < n - k; i++)
    {
        c_max = max(c_max, a[0][i]);
        dp[0][i] = c_max;
    }
    for (int i = 1; i < k; i++)
    {
        c_max = -1;
        for (int j = i; j < n - (k - i - 1); j++)
        {
            c_max = max(c_max, a[i][j] + dp[i - 1][j - 1]);
            dp[i][j] = c_max;
        }
    }
    c_max = -1;
    for (int i = k; i < n; i++)
    {
        c_max = max(c_max, dp[k - 1][i]);
    }
    cout << c_max << endl;
}

int main()
{
    freopen("../input.inp", "r", stdin);
    solve();
}