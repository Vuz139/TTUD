#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int y[MAX];
int x[MAX];
int d[MAX];
int c[MAX][MAX];
int visited[MAX];
int load[MAX];
int n, K, Q;
int segments;
int nbRoutes;
int ans;
int curAns;

void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    d[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
}
void solution()
{

    for (int k = 1; k <= K; k++)
    {
        queue<int> q;
        int s = y[k];
        for (int v = s; v != 0; v = x[v])
        {
            q.push(v);
        }
        if (!q.empty())
        {
            curAns += c[0][q.front()];
            q.push(0);
            while (!q.empty())
            {
                int t = q.front();
                if (t == 0)
                    break;
                q.pop();
                curAns += c[t][q.front()];
            }
        }
    }
    if (curAns < ans && curAns > 0)
        ans = curAns;
    curAns = 0;
}
bool check_X(int v, int k)
{
    if (v > 0 && visited[v])
        return false; // xe đã về hoặc depot đã được thăm
    if (load[k] + d[v] > Q)
        return false; // xe quá tải
    return true;
}

void Try_X(int v, int k)
{
    for (int i = 0; i <= n; i++)
    {
        if (check_X(i, k))
        {
            x[v] = i;
            visited[i] = 1;
            load[k] += d[i];
            segments++;
            if (i > 0)
            {
                Try_X(i, k);
            }
            else
            {
                if (k == K)
                {

                    if (segments == n + nbRoutes)
                    {
                        solution();
                    }
                }
                else
                {
                    Try_X(y[k + 1], k + 1);
                }
            }
            segments--;
            visited[i] = 0;
            load[k] -= d[i];
        }
    }
}

bool check_Y(int v, int k)
{
    if (v == 0)
        return true;
    if (load[k] + d[v] > Q) // xe hiện tại bị quá tải
        return false;
    return !visited[v];
}

void Try_Y(int k)
{
    for (int i = y[k - 1] + 1; i <= n; i++)
    {
        if (check_Y(i, k))
        {
            y[k] = i;
            segments += 1;

            visited[i] = 1;
            load[k] += d[i];

            if (k < K)
            {
                Try_Y(k + 1);
            }
            else
            {

                nbRoutes = segments;
                Try_X(y[1], 1); // du bo y[1],...,y[K], bat dau duyet cho diem tiep

                // theo cua y[1]
            }
            load[k] -= d[i];
            visited[i] = 0;
            segments -= 1;
        }
    }
}

void solve()
{
    for (int v = 1; v <= n; v++)
        visited[v] = 0;
    y[0] = 0;
    x[0] = 0;

    for (int i = 0; i <= K; i++)
    {
        load[i] = 0;
    }
    ans = INT_MAX;
    curAns = 0;
    segments = 0;
    Try_Y(1);
}
int main()
{
    freopen("input.inp", "r", stdin);
    input();
    solve();
    cout << ans;
}
