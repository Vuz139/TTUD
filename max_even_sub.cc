#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void solve()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> max_sum(n + 1);
    max_sum[0] = max(arr[0], 0);
    for (int i = 1; i < n; i++)
    {
        long long temp_sum = max_sum[i - 1] + arr[i];
        max_sum[i] = max(temp_sum, (long long)0);
    }
    long long curr_max = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max_sum[i] % 2 == 0)
            curr_max = max(curr_max, max_sum[i]);
    }
    if (LONG_MIN == curr_max)
    {
        cout << "NOT_FOUND";
        return;
    }
    cout << curr_max << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    solve();
}