
#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> childList;
map<string, string> parent;
map<string, int> Count;

string originPerson;

string getRoot()
{
    for (auto par : childList)
    {
        if (parent.find(par.first) == parent.end())
        {
            return par.first;
        }
    }
}

void setCountName()
{
    for (auto par : parent)
    {
        Count[par.first] = 0;
    }
}

void descendants(string name)
{

    if (childList[name].size() < 1)
    {
        Count[name] = 1;
    }
    else
    {
        Count[parent[name]]++;
        for (string child : childList[name])
        {

            descendants(child);
            Count[name] += Count[child];
        }
    }
}

int countGenerated(string name)
{
    int count = 1;
    if (name == originPerson)
    {
        return count;
    }
    else
    {
        count += countGenerated(parent[name]);
    }
    return count;
}

void solve()
{
    string a, b;
    while (1)
    {
        cin >> a;
        if (a == "***")
            break;
        cin >> b;
        parent[a] = b;
        childList[b].push_back(a);
    }
    setCountName();
    originPerson = getRoot();
    descendants(originPerson);

    while (1)
    {
        cin >> a;
        if (a == "***")
            break;
        cin >> b;
        if (a == "descendants")
        {
            cout << Count[b] << endl;
        }
        else if (a == "generation")
        {
            cout << countGenerated(b) << endl;
        }
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}
