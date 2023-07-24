#include <bits/stdc++.h>

using namespace std;

int modPrimePow(int a, int b, int p)
{
    int ret = 1;
    a %= p;
    b %= p - 1;
    while (b > 0) // vòng lặp phân tích b thành cơ số 2
    {
        if (b % 2 > 0) // ở vị trí có số 1 thì nhân với a^(2^i) tương ứng. Tất cả các phép nhân đều có phép mod p theo sau.
            ret = ret * a % p;
        a = a * a % p; // tính tiếp a^(2^(i+1)), a^1 -> a^2 -> a^4 -> a^8 -> a^16 v.v...
        b /= 2;
    }
    return ret;
}

void solve()
{
    int n, p;
    cin >> n >> p;
    string key;
    while (n--)
    {
        cin >> key;
        int res = 0;
        int len = key.length();
        for (int i = 0; i < len; i++)
        {
            res += ((int(key[i]) % p) * modPrimePow(256, len - 1, p)) % p;
        }
        cout << res << endl;
    }
}

int main()
{
    solve();
}