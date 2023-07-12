#include <bits/stdc++.h>
#define N 12
using namespace std;

int n;
int cities;
int currentPassenger;
int c[2 * N + 1][2 * N + 1];
int cmin = INT_MAX;
int visited[2 * N + 1];
int totalLength = 0;
int minSum = INT_MAX;
int x[2 * N + 1];

void solution()
{

    minSum = min(minSum, totalLength + c[x[cities - 1]][0]);
}

void TRY(int i)
{
    if (currentPassenger == 0)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0)
            {
                visited[j] = 1;
                x[i] = j;
                totalLength += c[x[i - 1]][j];
                currentPassenger = j;
                if (i == cities - 1)
                {
                    solution();
                }
                else
                {
                    if (totalLength + (cities - i - 1) * cmin < minSum)
                    {
                        TRY(i + 1);
                    }
                }
                totalLength -= c[x[i - 1]][j];
                visited[j] = 0;
                currentPassenger = 0;
            }
        }
    }
    else
    {
        x[i] = currentPassenger + n;
        int pre = currentPassenger;
        currentPassenger = 0;
        totalLength += c[x[i - 1]][x[i]];

        if (i == cities - 1)
        {
            solution();
        }
        else
        {
            if (totalLength + (cities - i - 1) * cmin < minSum)
            {
                TRY(i + 1);
            }
        }
        totalLength -= c[x[i - 1]][x[i]];
    }
}

void solve()
{
    cin >> n;
    cities = 2 * n + 1;

    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
                cmin = min(c[i][j], cmin);
        }
    }
    for (int i = 1; i < cities; i++)
    {
        visited[i] = 0;
    }

    x[0] = 0;
    currentPassenger = 0;
    TRY(1);

    cout << minSum;
}

int main()
{
    freopen("input.inp", "r", stdin);

    solve();
}
