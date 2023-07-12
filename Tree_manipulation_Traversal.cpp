// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int Max = 1e3;
// vector<int> Tree[Max];
// int root;

// void PreOrder(int u)
// {
//     cout << u << " ";
//     for (auto v : Tree[u])
//     {
//         PreOrder(v);
//     }
// }

// void InOrder(int u)
// {
//     if (Tree[u].size() != 0)
//         InOrder(Tree[u][0]);
//     cout << u << " ";
//     for (int i = 1; i < Tree[u].size(); i++)
//     {
//         InOrder(Tree[u][i]);
//     }
// }

// void PostOrder(int u)
// {
//     for (auto v : Tree[u])
//     {
//         PostOrder(v);
//     }
//     cout << u << " ";
// }

// void solve()
// {
//     string Temp;
//     while (1)
//     {
//         cin >> Temp;
//         if (Temp == "*")
//             break;
//         if (Temp == "MakeRoot")
//         {
//             cin >> root;
//         }
//         else if (Temp == "Insert")
//         {
//             int a, b;
//             cin >> a >> b;
//             Tree[b].push_back(a);
//         }
//         else if (Temp == "PreOrder")
//         {
//             PreOrder(root);
//             cout << '\n';
//         }
//         else if (Temp == "InOrder")
//         {
//             InOrder(root);
//             cout << '\n';
//         }
//         else if (Temp == "PostOrder")
//         {
//             PostOrder(root);
//             cout << '\n';
//         }
//     }
//     // for(auto v:Tree[root]) cout << v<< " ";
// }

// signed main()
// {
//     solve();
//     return -1;
// }

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> list_child;
int root;

void PostOrder(int node)
{

    for (int v : list_child[node])
    {
        PostOrder(v);
    }
    cout << node << ' ';
}
void PreOrder(int node)
{
    cout << node << ' ';
    for (int v : list_child[node])
    {
        PreOrder(v);
    }
}
vector<bool> status(1000, false);
void InOrder(int node)
{

    if (list_child[node].size() < 1)
    {
        cout << node << ' ';
    }
    else
    {
        InOrder(list_child[node][0]);
        cout << node << ' ';
    }
    int len = list_child[node].size();
    for (int i = 1; i < len; i++)
    {
        InOrder(list_child[node][i]);
    }
}

void solve()
{
    list_child.resize(1000);

    string temp;
    int u, k;
    while (1)
    {
        cin >> temp;
        if (temp == "*")
        {
            break;
        }
        if (temp == "MakeRoot")
        {
            cin >> root;
        }
        else if (temp == "Insert")
        {
            cin >> u >> k;
            list_child[k].push_back(u);
        }
        else if (temp == "InOrder")
        {
            InOrder(root);
            cout << endl;
        }
        else if (temp == "PreOrder")
        {
            PreOrder(root);
            cout << endl;
        }
        else if (temp == "PostOrder")
        {
            PostOrder(root);
            cout << endl;
        }
    }
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}