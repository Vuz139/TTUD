#include <bits/stdc++.h>

using namespace std;
map<string, bool> db;

void solve()
{
    string query, keyword;

    while (1)
    {
        cin >> query;
        if (query == "*")
            break;
        else
        {
            db[query] = true;
        }
    }
    while (1)
    {
        cin >> query;
        if (query == "***")
            break;
        else if (query == "find")
        {
            cin >> keyword;
            cout << db[keyword] << endl;
        }
        else if (query == "insert")
        {
            cin >> keyword;
            if (db[keyword])
            {
                cout << 0 << endl;
            }
            else
            {
                db[keyword] = true;
                cout << 1 << endl;
            }
        }
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}