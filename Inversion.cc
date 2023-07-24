#include <bits/stdc++.h>

using namespace std;

int n;
const int MOD = 1e9 + 7;
int a[1000002];
int temp[1000002];
int _merge(int l, int mid, int r)
{
    if (r - l == 1)
    {
        if (a[l] > a[r])
        {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int i = l, j = mid + 1, k = l;
    int inv_count = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }
    for (i = l; i <= r; i++)
    {
        a[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(int l, int r)
{
    int mid = (l + r) / 2;
    int inv_c = 0;
    if (r > l)
    {

        int inv_l = mergeSort(l, mid) % MOD;
        int inv_r = mergeSort(mid + 1, r) % MOD;
        int inv = _merge(l, mid, r) % MOD;
        // cout << "L: " << l << " R: " << r << ", " << inv_l << ' ' << inv_r << ' ' << inv << endl;
        inv_c = inv + inv_l + inv_r;
    }
    return inv_c % MOD;
}

void solve()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << mergeSort(0, n - 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    solve();
}