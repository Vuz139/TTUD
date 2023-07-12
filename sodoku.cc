#include <bits/stdc++.h>
using namespace std;

const int row = 9;
int count_ = 0;
int board[row][row];

bool check(int value, int r, int c)
{
    int r_sub = r / 3;
    int c_sub = c / 3;
    for (int i = 0; i < row; i++)
    {
        if (board[r][i] == value)
            return false;
        if (board[i][c] == value)
            return false;
    }
    for (int i = r_sub * 3; i < r_sub * 3 + 3; i++)
    {
        for (int j = c_sub * 3; j < c_sub * 3 + 3; j++)
        {
            if (board[i][j] == value)
                return false;
        }
    }
    return true;
}

void TRY(int r, int c)
{
    if (board[r][c] != 0)
    {
        if (c == row - 1)
        {
            if (r == row - 1)
            {
                count_++;
                return;
            }
            else
            {
                TRY(r + 1, 0);
            }
        }
        else
        {
            TRY(r, c + 1);
        }
    }
    else
    {
        for (int i = 1; i <= row; i++)
        {
            if (check(i, r, c))
            {
                board[r][c] = i;

                if (c == row - 1)
                {
                    if (r == row - 1)
                    {
                        count_++;
                        return;
                    }
                    else
                    {
                        TRY(r + 1, 0);
                    }
                }
                else
                {
                    TRY(r, c + 1);
                }
                board[r][c] = 0;
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> board[i][j];
        }
    }
    TRY(0, 0);
    // TRY(0, 0);
    cout << count_ * 2;
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}