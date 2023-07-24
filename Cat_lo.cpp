#include <bits/stdc++.h>

using namespace std;
const int max_ = 1e4;
int n;
int bTree[max_];
int prices[max_];
int min_loss = INT_MAX;

void insert_to_bTree(int value, int p)
{
    if (bTree[p] > value)
        min_loss = min(min_loss, bTree[p] - value);
    if (bTree[p] == 0)
    {
        bTree[p] = value;
        return;
    }
    if (value < bTree[p])
    {

        insert_to_bTree(value, 2 * p);
    }
    else
    {
        insert_to_bTree(value, 2 * p + 1);
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    bTree[0] = prices[0];
    for (int i = 1; i < n; i++)
    {
        insert_to_bTree(prices[i], 0);
    }
    cout << min_loss << endl;
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}