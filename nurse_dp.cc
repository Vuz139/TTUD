#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
int a[1001];
int b[1001];

void solve()
{
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++)
    {
        a[i] = 0;
    }
    b[1] = 1;
    a[k1] = 1;
    b[0] = 1;
    for (int i = k1 + 1; i <= n; i++)
    {

        b[i] = a[i - 1];
        for (int j = k1; j <= k2; j++)
        {
            a[i] += b[i - j];
        }
    }
    cout << a[n] + b[n] << endl;
}

int main()
{
    solve();
}
