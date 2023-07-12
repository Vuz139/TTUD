#include <bits/stdc++.h>

using namespace std;
const int max_ = 1e3;

int n, m;
struct Node
{
    int height;
    int left;
    int right;
    int index;
};
Node h[max_][max_];

int compute_max_from_row(int row)
{
    stack<Node> st;
    while (!st.empty())
    {
        st.pop();
    }
    // find left
    for (int i = 0; i < m; i++)
    {
        h[row][i].index = i;
        while (!st.empty())
        {
            Node temp = st.top();
            if (temp.height < h[row][i].height)
            {
                h[row][i].left = temp.index;
                st.push(h[row][i]);
                break;
            }
            else
            {
                st.pop();
            }
        }
        if (st.empty())
        {
            h[row][i].left = -1;
            st.push(h[row][i]);
        }
    }
    while (!st.empty())
    {
        st.pop();
    }
    // find right
    for (int i = m - 1; i >= 0; i--)
    {
        h[row][i].index = i;
        while (!st.empty())
        {
            Node temp = st.top();
            if (temp.height < h[row][i].height)
            {
                h[row][i].right = temp.index;
                st.push(h[row][i]);
                break;
            }
            else
            {
                st.pop();
            }
        }
        if (st.empty())
        {
            h[row][i].right = m;
            st.push(h[row][i]);
        }
    }
    int curr_max = -1;
    // cout << "row: " << row << endl;
    for (int i = 0; i < m; i++)
    {
        // cout << h[row][i].left << " " << h[row][i].right << endl;
        curr_max = max(curr_max, h[row][i].height * (h[row][i].right - h[row][i].left - 1));
    }
    return curr_max;
}

void solve()
{
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        h[0][i].height = a[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                h[i][j].height = 0;
            else
            {
                h[i][j].height = 1 + h[i - 1][j].height;
            }
        }
    }
    int max_ = -1;
    for (int i = 0; i < n; i++)
    {
        max_ = max(max_, compute_max_from_row(i));
    }
    cout << max_ << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.inp", "r", stdin);
    solve();
}