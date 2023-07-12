#include <bits/stdc++.h>

using namespace std;

const int max_ = 1e6;
int n;
int price[max_];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int min_slice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (price[i] > price[j])
                min_slice = min(min_slice, price[i] - price[j]);
        }
    }
    cout << min_slice << endl;
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}
