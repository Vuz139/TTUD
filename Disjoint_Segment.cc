#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> x;
vector<pair<int, int>> S;
bool compareSecond(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

bool check(pair<int, int> v)
{
    if (S.empty())
        return true;

    if (v.first > S.back().second)
    {
        return true;
    }
    return false;
}

void greedy()
{

    for (int i = 0; i < n; i++)
    {
        if (check(x[i]))
        {
            S.push_back(x[i]);
        }
    }
}

void solve()
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x.push_back(make_pair(a, b));
    }

    sort(x.begin(), x.end(), compareSecond);
    greedy();
    cout << S.size() << endl;
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}
