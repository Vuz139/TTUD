#include <bits/stdc++.h>

using namespace std;

const int max_ = 13;

int n, K, Q;
int d_[max_];
int c_[max_][max_];
int visited[max_];
int x[2 * max_];
int curr_dis = 0;
int min_dis = INT_MAX;
int curr_Q;

void print_x()
{
    for (int i = 0; i < 2 * max_; ++i)
    {
        cout << x[i] << ' ';
    }
    cout << "DIS: " << curr_dis << endl;
}

bool check(int j)
{
    if (visited[j])
        return false;
    if (curr_Q < d_[j])
        return false;
    return true;
}

void TRY(int i, int k)
{
    int go = 0;
    for (int j = 1; j <= n; j++)
    {
        if (check(j))
        {
            go = 1;
            x[i] = j;
            curr_dis += c_[x[i - 1]][j];
            curr_Q -= d_[j];
            visited[j] = 1;
            TRY(i + 1, k);

            curr_dis -= c_[x[i - 1]][j];
            curr_Q += d_[j];
            visited[j] = 0;
        }
    }
    if (!go)

    {
        if (k != K - 1)
        {
            int temp = curr_Q;
            curr_Q = Q;
            curr_dis += c_[x[i - 1]][0];
            x[i] = 0;
            TRY(i + 1, k + 1);
            curr_Q = temp;
            curr_dis -= c_[x[i - 1]][0];
        }
        else
        {
            int check = 0;
            for (int i = 1; i <= n; i++)
            {
                if (visited[i])
                    continue;
                check = 1;
            }
            if (!check)
            {
                // print_x();
                min_dis = min(min_dis, curr_dis + c_[x[i - 1]][0]);
            }
        }
    }
}

void solve()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d_[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c_[i][j];
        }
    }
    x[0] = 0;
    visited[0] = 1;
    curr_Q = Q;
    TRY(1, 0);
    cout << min_dis;
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.oup", "w+", stdout);
    solve();
}