#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e5 + 1;

int n;
int a[MAX_];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }
    string query;
    int x;
    while (1)
    {
        cin >> query;
        if (query == "*")
        {
            break;
        }
        else if (query == "insert")
        {
            cin >> x;
            pq.push(x);
        }
        else if (query == "delete-max")
        {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}

int main()
{
    freopen("../input.inp", "r", stdin);
    freopen("../output.oup", "w", stdout);

    solve();
}