#include <bits/stdc++.h>

using namespace std;

int n, T, D;
int a[101];
int t[101];
int dp[101][101]; // dp[i][j] là max trong i điểm đầu tiên và dùng j thời gian
int res_ = -1;

void solve()
{
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][t[i]] = a[i];
        res_ = max(res_, dp[i][t[i]]);
        for (int j = 1; j <= D; j++)
        {
            if (i > j)
            {
                int b = i - j;
                for (int k = 1; k <= T - t[i]; k++)
                {
                    if (dp[b][k] > 0)
                    {
                        dp[i][k + t[i]] = max(dp[b][k] + a[i], dp[i][k + t[i]]);
                        res_ = max(res_, dp[i][k + t[i]]);
                    }
                }
            }
        }
    }
    cout << res_ << endl;
}
int main()
{
    solve();
}