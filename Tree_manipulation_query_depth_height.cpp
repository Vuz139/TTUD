#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> list_child;
vector<int> parent;
vector<int> height;
vector<int> depth;

void findHeight(int node)
{

    if (list_child[node].size() < 1)
    {
        height[node] = 1;
        return;
    }
    height[node] = -1;
    for (int x : list_child[node])
    {
        int temp = 1;
        findHeight(x);
        temp = height[x] + 1;
        height[node] = max(temp, height[node]);
    }
}

void findDepth(int node)
{

    if (parent[node] == node)
    {
        depth[node] = 1;
        return;
    }
    findDepth(parent[node]);
    depth[node] = 1 + depth[parent[node]];
}

void solve()
{
    string temp;
    int a, b;
    while (1)
    {
        cin >> temp;
        if (temp == "*")
            break;
        else if (temp == "MakeRoot")
        {
            cin >> a;
            parent[a] = a;
        }
        else if (temp == "Insert")
        {
            cin >> a >> b;
            list_child[b].push_back(a);
            parent[a] = b;
        }
        else if (temp == "Height")
        {
            cin >> a;
            findHeight(a);
            cout << height[a] << endl;
        }
        else if (temp == "Depth")
        {

            cin >> a;
            findDepth(a);
            cout << depth[a] << endl;
        }
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    list_child.resize(1000);
    parent.resize(1000);
    height.resize(1000);
    depth.resize(1000);
    solve();
}