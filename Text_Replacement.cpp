#include <bits/stdc++.h>

using namespace std;

string p1, p2, t;

void solve()
{
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);

    int len_p1 = p1.length();

    while (1)
    {
        int pos = t.find(p1);

        if (pos > t.length())
            break;
        t.replace(pos, len_p1, p2);
    }
    cout << t;
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}