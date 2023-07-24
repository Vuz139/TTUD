#include <bits/stdc++.h>

using namespace std;

stack<int> st;

void solve()
{
    string query;
    int value;
    while (1)
    {
        cin >> query;
        if (query == "PUSH")
        {
            cin >> value;
            // cout << value << endl;
            st.push(value);
        }
        else if (query == "POP")
        {
            if (st.empty())
            {
                cout << "NULL" << endl;
                continue;
            }
            cout << st.top() << endl;
            st.pop();
        }
        else if (query == "#")
        {
            break;
        }
    }

    // while (!st.empty())
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}