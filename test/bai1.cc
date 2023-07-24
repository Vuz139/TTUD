#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e5 + 1;
int a[MAX_];
int n, k, m;
int Q = 0;

void solve()
{
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int p1, p2;
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
        curr_sum += a[i];
    }
    p1 = 0, p2 = k;
    while (p2 < n)
    {
        if (curr_sum == m)
        {
            Q++;
        }
        curr_sum -= a[p1];
        curr_sum += a[p2];
        p1++;
        p2++;
    }
    cout << Q << endl;
}

int main()
{
    freopen("../input.inp", "r", stdin);
    solve();
}