// #include <bits/stdc++.h>
// using namespace std;

// vector<int> dp;

// int TRY(int sum)
// {
//     if (dp[sum] != 0)
//     {
//         return dp[sum];
//     }

//     int res = 0;
//     for (int i = 0; i <= sum - 1; i++)
//     {
//         res += TRY(i);
//     }
//     dp[sum] = res;
//     return res;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     dp.resize(n + 1, 0);
//     dp[0] = 1;
//     dp[1] = 1;
//     cout << (TRY(n)) << endl;
// }

// int main()
// {
//     solve();
// }
#include <bits/stdc++.h>
using namespace std;

int n;
void countWays()
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[n];
}

int main()
{
    cin >> n;

    countWays();
}
