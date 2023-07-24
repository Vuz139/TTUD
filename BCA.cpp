#include <bits/stdc++.h>

using namespace std;

int m, n;
int T[32][32];
int k;
int conflic[32][32];
int load = INT_MAX;
int t_load[32];
vector<vector<int>> t_courses;

bool check_teacher(int course, int t)
{

    for (int c : t_courses[t])
    {
        if (!conflic[course][c])
        {
            continue;
        }
        return false;
    }

    int len = T[t][0];
    for (int j = 1; j <= len; j++)
    {
        if (course == T[t][j])
            return true;
    }
    return false;
}

void solution()
{
    int max_load = -1;
    for (int i = 0; i < m; i++)
    {
        if (max_load < t_load[i])
            max_load = t_load[i];
    }
    load = min(load, max_load);
}

void TRY(int i)
{

    for (int t = 0; t < m; t++)
    {
        if (check_teacher(i, t))
        {
            t_load[t]++;
            t_courses[t].push_back(i);

            if (i == n)
            {
                solution();
            }
            else
            {
                if (t_load[t] < load)
                    if (curr_maxLoad < load)
                        TRY(i + 1);
            }
            t_load[t]--;
            t_courses[t].pop_back();
        }
    }
}

void solve()
{
    cin >> m >> n;
    t_courses.resize(m + 2);
    int temp;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        T[i][0] = temp;
        for (int j = 1; j <= temp; j++)
        {
            cin >> T[i][j];
        }
    }
    cin >> k;
    int temp2;
    for (int i = 0; i < k; i++)
    {
        cin >> temp >> temp2;
        conflic[temp][temp2] = 1;
        conflic[temp2][temp] = 1;
    }
    TRY(1);
    cout << load;
}

int main()
{
    // freopen("input.inp", "r", stdin);

    solve();
}