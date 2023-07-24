#include <bits/stdc++.h>

using namespace std;

map<char, char> paranthesis;

void solve()
{
    string quotes;
    cin >> quotes;
    paranthesis[')'] = '(';
    paranthesis[']'] = '[';
    paranthesis['}'] = '{';
    paranthesis['('] = '0';
    paranthesis['['] = '0';
    paranthesis['{'] = '0';
    bool check = true;
    int len = quotes.size();
    stack<char> st;
    for (int i = 0; i < len; i++)
    {

        char chh = quotes[i];
        if (paranthesis[chh] == '0')
        {
            st.push(chh);
        }
        else
        {
            if (!st.empty())
            {
                if (paranthesis[chh] != st.top())
                {
                    check = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                check = false;
                break;
            }
        }
    }
    if (st.empty())
    {

        if (check)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}