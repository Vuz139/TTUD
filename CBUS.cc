#include <bits/stdc++.h>
using namespace std;
const int MAX_ = 24;

int n, k;
int m[MAX_][MAX_];
int visited[MAX_];
int x[MAX_];
int min_route = INT_MAX;
int c_max = INT_MAX;
int curr_route = 0;
int curr_passenger = 0;
vector<int> passengers;
void TRY(int i)
{
    if (curr_passenger < k)
    {
        for (int j = 1; j < n; j++)
        {
            if (!visited[j])
            {
                passengers.push_back(j);
                x[i] = j;
                visited[j] = 1;
                curr_route += m[x[i - 1]][j];
                if (curr_route * c_max * (2 * n - i) < min_route)
                {
                    curr_passenger++;
                    TRY(i + 1);
                    curr_passenger--;
                }
                visited[j] = false;
                curr_route -= m[x[i - 1]][j];

                passengers.pop_back(j);
            }
        }
    }
    else
    {
        for (int j : passengers)
        {
            if (!visited[j + n])
            {
            }
        }
    }
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> m[i][j];
            c_max = min(c_max, m[i][j]);
        }
    }
    x[0] = 0;
    TRY(1);
}
