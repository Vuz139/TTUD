#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 99;
int maze[MAX][MAX];
int d[MAX][MAX];
int c, r;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int startC, startR;

int process()
{
    q.push({startR, startC});
    d[startR][startC] = 0;
    maze[startR][startC] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + p.first;
            int y = dy[i] + p.second;
            // cout << "x: " << x << " y: " << y << endl;
            if (x < 1 || y < 1 || x > r || y > c)
                return d[p.first][p.second] + 1;
            else if (maze[x][y] != 1)
            {
                d[x][y] = d[p.first][p.second] + 1;
                maze[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    return -1;
}

void solve()
{
    cin >> r >> c;
    cin >> startR >> startC;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << process();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.inp", "r", stdin);

    solve();
}