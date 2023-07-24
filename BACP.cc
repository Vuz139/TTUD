#include <bits/stdc++.h>

using namespace std;

int n, m;
int mt[17][17];
int visited[17];
int credits[17];
int load[6];
int min_load = INT_MAX;
int curr = 0;
void add(int v)
{

    for (int i = 0; i < m; i++)
    {
        if (load[curr] >= load[i])
        {
            curr = i;
        }
    }
    load[curr] += v;
}

bool check(int j)
{
    if (visited[j])
        return false;
    for (int i = 0; i < n; i++)
    {
        if (mt[i][j] == 1)
        {
            if (!visited[i])
                return false;
        }
    }
    return true;
}
void solution()
{
    int curr_max = -1;
    for (int i = 0; i < m; i++)
    {
        curr_max = max(curr_max, load[i]);
    }
    min_load = min(min_load, curr_max);
}
void TRY(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (check(j))
        {
            visited[j] = 1;
            add(credits[j]);
            int temp = curr;
            if (i == n - 1)
            {
                solution();
            }
            else
            {
                TRY(i + 1);
            }
            load[temp] -= credits[j];
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> credits[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mt[i][j];
        }
    }
    TRY(0);
    cout << min_load;
}
int main()
{
    solve();
}