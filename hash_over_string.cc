#include <bits/stdc++.h>

using namespace std;

int n, m;
int exp_[205];

void compute_exp()
{
    int temp = (256 % m);
    exp_[0] = 1;
    for (int i = 1; i < 205; i++)
    {
        exp_[i] = (temp * exp_[i - 1]) % m;
    }
}

void hash_string(string s)
{
    const int len = s.size();
    int mod = 0;
    for (int i = 0; i < len; i++)
    {
        mod += ((int)s[i] * exp_[len - i - 1]) % m;
        mod %= m;
    }
    cout << mod << endl;
}

void solve()
{
    cin >> n >> m;
    compute_exp();
    string s;
    while (n > 0)
    {
        cin >> s;
        hash_string(s);
        n--;
    }
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}