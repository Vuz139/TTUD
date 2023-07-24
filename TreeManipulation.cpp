#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> list_child;
// vector<int> parent;

int CountLeaves(int u)
{
    if (list_child[u].size() < 1)
    {
        return 1;
    }
    else
    {
        int sum = 0;
        for (int node : list_child[u])
        {
            sum += CountLeaves(node);
        }
        return sum;
    }
}

int CountKChildren(int u, int k)
{
    int count = 0;
    if (list_child[u].size() == k)
    {
        count++;
    }
    for (int node : list_child[u])
    {
        count += CountKChildren(node, k);
    }
    return count;
}

void solve()
{
    string query;
    int a, b;
    while (1)
    {
        cin >> query;
        if (query == "MakeRoot")
        {
            cin >> a;
        }
        else if (query == "Insert")
        {
            cin >> a >> b;
            list_child[b].push_back(a);
        }
        else if (query == "CountLeaves")
        {
            cin >> a;
            cout << CountLeaves(a) << endl;
        }
        else if (query == "CountKChildren")
        {
            cin >> a >> b;
            cout << CountKChildren(a, b) << endl;
        }
        else if (query == "*")
            break;
    }
}

int main()
{
    list_child.resize(1000);

    freopen("input.inp", "r", stdin);
    solve();
}