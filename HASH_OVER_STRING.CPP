#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
int m;
int exps[MAX];
int exp_()
{
    exps[0] = 1;
    const int xxx = 256 % m;
    for (int i = 1; i < 201; i++)
    {
        exps[i] = ((exps[i - 1] % m) * xxx) % m;
    }
}

void compute()
{
    string temp;
    cin >> temp;
    int len = temp.length();

    int sum = 0;
    for (int i = 0; i <= len; i++)
    {
        sum += ((int)temp[i] * exps[len - i - 1]);
        sum %= m;
    }
    cout << sum << endl;
}

void solve()
{
    int n;
    cin >> n >> m;
    exp_();
    while (n > 0)
    {
        compute();
        n--;
    }
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}