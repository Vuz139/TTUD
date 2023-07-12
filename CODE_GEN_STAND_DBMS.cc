#include <bits/stdc++.h>

using namespace std;

const int max_case = 1e6;

int n, L;
int a[max_case];
string key;
void gen(int x)
{
    for (int j = L - 1; j >= 0; j--)
    {
        int p = pow(10, j);
        int temp = x % p;
        x /= p;
        if (temp < 0)
            break;
        cout << temp << endl;
        key[j] = (char)temp;
    }
    cout << key << endl;
}

void solve()
{
    cin >> n >> L;
    key.resize(L, '0');

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        gen(a[i]);
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}