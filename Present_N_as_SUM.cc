#include <bits/stdc++.h>

using namespace std;

int N;
int x[1001];
int curr_sum;
int counts = 0;
void solution()
{
    if (curr_sum == N)
    {
        counts++;
    }
}

void TRY(int i, int k)
{
    int top = N - curr_sum;
    for (int j = x[i - 1]; j <= top; j++)
    {
        x[i] = j;
        curr_sum += j;
        if (i == k - 1)
        {
            solution();
        }
        else
        {
            if (curr_sum < N)
            {
                TRY(i + 1, k);
            }
        }
        curr_sum -= j;
    }
}

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            curr_sum = j;
            x[0] = j;
            TRY(1, i);
        }
    }
    cout << counts + 1;
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}