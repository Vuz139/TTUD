#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
int x[1001];
int result;
int cnt;

void solution()
{
    // for (int i = 0; i < n; i++)
    // {
    //     cout << x[i] << " ";
    // }
    // cout << endl;
    result++;
}

bool check(int j, int i)
{
    if (i == 0)
        return true;
    if (j == 0)
    {
        if (x[i - 1] == 0)
            return false;
        else if (i > n - k1 - 1 && i < n - 1)
        {
            return false;
        }
        else
        {
            if (cnt < k1)
                return false;
        }
    }
    else
    {
        if (cnt >= k2)
            return false;
    }
    return true;
}

void TRY(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        if (check(j, i))
        {
            int temp = cnt;
            x[i] = j;
            if (i == n - 1)
            {
                solution();
            }
            else
            {
                if (j == 1)
                {
                    cnt++;
                    TRY(i + 1);
                    cnt--;
                }
                else
                {
                    cnt = 0;
                    TRY(i + 1);
                    cnt = temp;
                }
            }
        }
    }
}

void solve()
{
    result = 0;
    cnt = 0;
    cin >> n >> k1 >> k2;
    TRY(0);
    cout << result;
}
int main()
{
    solve();
}