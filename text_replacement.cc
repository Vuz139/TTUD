#include <bits/stdc++.h>

using namespace std;

string T, p1, p2;

void solve()
{
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, T);
    int len_p1 = p1.length();

    while (1)
    {
        int pos = T.find(p1);

        if (pos > T.length())
            break;
        T.replace(pos, len_p1, p2);
    }
    cout << T;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}