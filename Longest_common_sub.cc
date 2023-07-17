#include <bits/stdc++.h>

using namespace std;
const int MAX_ = 1e5 + 1;
int n, m;
int X[MAX_];
int Y[MAX_];
vector<vector<int>> dp;

int main()
{
    cin >> n >> m;
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> Y[i];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(m + 1, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
}
