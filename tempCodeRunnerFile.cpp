#include <bits/stdc++.h>

using namespace std;
int n, m;
pair<int, int> curr_pos;
map<pair<int, int>, bool> maze;

void move_left()
{
    if (curr_pos.second - 1 < 1)
    {
        return;
    }
    if (maze[{curr_pos.first, curr_pos.second - 1}] == true)
    {
        return;
    }
    curr_pos.second--;
}
void move_right()
{
    if (curr_pos.second + 1 > m)
    {
        return;
    }
    if (maze[{curr_pos.first, curr_pos.second + 1}] == true)
    {
        return;
    }
    curr_pos.second++;
}

void move_up()
{
    if (curr_pos.first - 1 < 1)
    {
        return;
    }
    if (maze[{curr_pos.first - 1, curr_pos.second}] == true)
    {
        return;
    }
    curr_pos.first--;
}

void move_down()
{
    if (curr_pos.first + 1 > n)
    {
        return;
    }
    if (maze[{curr_pos.first + 1, curr_pos.second}] == true)
    {
        return;
    }
    curr_pos.first++;
}

void solve()
{
    cin >> n >> m;
    cin >> curr_pos.first >> curr_pos.second;
    int cell;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> cell;
            if (cell == 1)
                maze[make_pair(i, j)] = true;
        }
    }

    string order;
    while (1)
    {
        cin >> order;
        if (order == "move-left")
        {
            move_left();
        }
        else if (order == "move-right")
        {
            move_right();
        }
        else if (order == "move-up")
        {
            move_up();
        }
        else if (order == "move-down")
        {
            move_down();
        }
        else if (order == "#")
        {
            break;
        }
    }
    cout << curr_pos.first << " " << curr_pos.second << endl;
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}