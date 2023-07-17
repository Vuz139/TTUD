#include <bits/stdc++.h>

using namespace std;

const int max_case = 1e6;

int n, L;
string prefixs[50];
void compute()
{
    prefixs[0] = "0";
    for (int i = 1; i < 50; i++)
    {
        prefixs[i] = "0" + prefixs[i - 1];
    }
}
void solve()
{
    cin >> n >> L;
    compute();
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp.length() < L)
        {
            cout << prefixs[L - temp.length() - 1];
        }
        cout << temp << endl;
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}