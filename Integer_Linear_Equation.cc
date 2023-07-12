#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[35];
int curr_sum = 0;
int count_ = 0;
void solution()
{
    if ((m - curr_sum) % a[n - 1] == 0 && curr_sum < m)
    {
        count_++;
    }
}

void TRY(int i)
{
    for (int j = 1; j <= (m - curr_sum) / a[i]; j++)
    {
        curr_sum += a[i] * j;
        if (i == n - 2)
        {
            solution();
        }
        else
        {
            if (curr_sum < m)
                TRY(i + 1);
        }
        curr_sum -= a[i] * j;
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    TRY(0);
    cout << count_;
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}