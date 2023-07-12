#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> b_tree;
int root;
int check_height(int node)
{
    if (node == 0 || b_tree[node].first == 0 && b_tree[node].second == 0)
    {
        return 1;
    }
    else
    {
        return 1 + max(check_height(b_tree[node].first), check_height(b_tree[node].second));
    }
}

bool check_balance(int node)
{
    if (b_tree[node].first == 0 && b_tree[node].second == 0)
        return true;
    return check_height(b_tree[node].first) == check_height(b_tree[node].second) && check_balance(b_tree[node].first) && check_balance(b_tree[node].second);
}
void solve()
{
    b_tree.resize(50000);

    string temp;
    int child, parent;
    cin >> temp;
    cin >> root;
    while (1)
    {
        cin >> temp;
        if (temp == "AddLeft")
        {
            cin >> child >> parent;
            if (b_tree[parent].first == 0)
            {
                b_tree[parent].first = child;
            }
        }
        else if (temp == "AddRight")
        {
            cin >> child >> parent;
            if (b_tree[parent].second == 0)
            {
                b_tree[parent].second = child;
            }
        }
        else if (temp == "*")
            break;
    }

    cout << !check_balance(root) << " " << check_height(root) << endl;
    // printTree(root);
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}