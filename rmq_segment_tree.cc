#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int arr_input[MAXN];
vector<int> st_tree;
int n, m;

void build_tree(int id, int l, int r)
{
    if (l == r)
    {
        st_tree[id] = arr_input[l];
        return;
    }

    int mid = (l + r) / 2;
    build_tree(2 * id, l, mid);
    build_tree(2 * id + 1, mid + 1, r);

    if (st_tree[2 * id] <= st_tree[2 * id + 1])
    {
        st_tree[id] = st_tree[2 * id];
    }
    else
    {
        st_tree[id] = st_tree[2 * id + 1];
    }
}

int getMax(int id, int l, int r, int i, int j)
{

    if (r < i || j < l)
    {
        return INT_MAX;
    }
    if (i <= l && r <= j)
    {
        return st_tree[id];
    }
    int mid = (l + r) / 2;
    int maxL = getMax(2 * id, l, mid, i, j);
    int maxR = getMax(2 * id + 1, mid + 1, r, i, j);
    if (maxL <= maxR)
    {
        return maxL;
    }
    else
        return maxR;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr_input[i];
    }
    st_tree.resize(4 * n + 4);
    build_tree(1, 0, n - 1);
    cin >> m;
    int u, v;

    int sum = 0;
    while (m > 0)
    {
        cin >>
            u >> v;

        sum += getMax(1, 0, n - 1, u, v);
        m--;
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.inp", "r", stdin);
    // freopen("output.outp", "w", stdout);
    solve();
}