#include <bits/stdc++.h>

using namespace std;

deque<int> link_list;

deque<int>::iterator find(int value)
{
    deque<int>::iterator itr;
    itr = find(link_list.begin(), link_list.end(), value);
    if (itr != link_list.end())
    {
        return itr;
    }
    else
    {
        return link_list.end();
    }
}
void print()
{
    for (int v : link_list)
    {
        cout << v << " ";
    }
    cout << endl;
}
void solve()
{
    int u, k;
    cin >> u;
    for (int i = 0; i < u; i++)
    {
        cin >> k;
        link_list.push_back(k);
    }

    string temp;

    deque<int>::iterator itr;
    while (1)
    {
        cin >> temp;

        if (temp == "#")
            break;
        else if (temp == "addfirst")
        {
            cin >> k;
            itr = find(k);

            if (itr != link_list.end())
                continue;
            link_list.push_front(k);
        }
        else if (temp == "addlast")
        {
            cin >> k;

            itr = find(k);

            if (itr != link_list.end())
                continue;
            link_list.push_back(k);
        }
        else if (temp == "addafter")
        {
            cin >> u >> k;
            itr = find(k);
            if (itr != link_list.end())
            {
                itr = find(u);

                if (itr == link_list.end())
                {
                    link_list.insert(itr + 1, u);
                }
            }
        }
        else if (temp == "addbefore")
        {
            cin >> u >> k;
            itr = find(k);
            if (itr != link_list.end())
            {
                itr = find(u);

                if (itr == link_list.end())
                {
                    link_list.insert(itr, u);
                }
            }
        }
        else if (temp == "remove")
        {
            cin >> k;
            itr = find(k);
            link_list.erase(itr, itr + 1);
        }
        else if (temp == "reverse")
        {
            link_list.rend();
        }
    }

    print();
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}