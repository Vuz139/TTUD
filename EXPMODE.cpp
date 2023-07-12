#include <bits/stdc++.h>

using namespace std;
// const int MOD = 1e9 + 7;
const int MOD = 143;
int exp_mode(unsigned long long x, unsigned long long n)
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
    return ans;
}

int main()
{
    unsigned long long x, n;
    cin >> x >> n;
    cout << exp_mode(x, n);
}
