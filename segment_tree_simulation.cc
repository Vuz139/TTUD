#include <bits/stdc++.h>

using namespace std;

vector<int> stTree;
vector<int> arr_;
int n, numOfQueries;

void build(int id, int l, int r)
{
    if (l == r)
    {
        stTree[id] = arr_[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    stTree[id] = max(stTree[2 * id], stTree[2 * id + 1]);
}

void updateTree(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        stTree[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    updateTree(2 * id, l, mid, i, v);
    updateTree(2 * id + 1, mid + 1, r, i, v);

    stTree[id] = max(stTree[2 * id], stTree[2 * id + 1]);
}

int getMax(int id, int l, int r, int i, int j)
{
    if (j < l || r < i)
    {
        return -1;
    }
    if (i <= l && r <= j)
    {
        return stTree[id];
    }

    int mid = (l + r) / 2;
    int maxL = getMax(2 * id, l, mid, i, j);
    int maxR = getMax(2 * id + 1, mid + 1, r, i, j);
    return max(maxL, maxR);
}

void solve()
{
    cin >> n;
    stTree.resize(4 * n + 4);
    arr_.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr_[i];
    }
    build(1, 1, n);
    cin >> numOfQueries;
    string query;
    int i, v, j;
    while (numOfQueries > 0)
    {

        cin >> query;
        if (query == "get-max")
        {
            cin >> i >> j;
            cout << getMax(1, 1, n, i, j) << endl;
        }
        else if (query == "update")
        {
            cin >> i >> v;
            updateTree(1, 1, n, i, v);
        }

        numOfQueries--;
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}