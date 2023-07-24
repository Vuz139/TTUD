#include <bits/stdc++.h>

using namespace std;

queue<int> st;

void POPP()
{
    if (!st.empty())
    {
        cout << st.front() << endl;
        st.pop();
    }
    else
    {
        cout << "NULL" << endl;
    }
}

void solve()
{
    string q;
    int num;
    while (true)
    {
        cin >> q;
        if (q == "POP")
        {
            POPP();
        }
        else if (q == "PUSH")
        {
            cin >> num;
            st.push(num);
        }
        else if (q == "#")
        {
            break;
        }
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}