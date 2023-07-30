#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void mod(int x, int n)
{

    unsigned long long ans = 1;
    unsigned long long base = x % MOD;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        n /= 2;
    }
    cout << ans << endl;
}

int main()
{
    int x, n;
    cin >> x >> n;
    mod(x, n);
}