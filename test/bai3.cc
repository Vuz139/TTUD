#include <bits/stdc++.h>

using namespace std;

int n;
int a[23];
int A, B;
int Q = 0;
int curr_sum = 0;
int visited[23];

void solution()
{
    if (curr_sum >= A && curr_sum <= B)
    {
        Q++;
    }
}

void TRY(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        if (i == n)
        {
            solution();
            break;
        }
        else
        {

            if (j == 0)
            {

                TRY(i + 1);
            }
            else
            {

                curr_sum += a[i];
                if (curr_sum <= B)
                {

                    TRY(i + 1);
                }
                curr_sum -= a[i];
            }
        }
    }
}

void solve()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    TRY(0);
    cout << Q;
}
int main()
{
    freopen("../input.inp", "r", stdin);
    // freopen("../output.oup", "w", stdout);

    solve();
}