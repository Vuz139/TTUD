#include <bits/stdc++.h>

using namespace std;

int x[41];
int k, n;
int curr_sum = 0;

void solution()
{
    if (curr_sum == n)
    {
        for (int i = 0; i < k; i++)
        {
            cout << x[i] << ' ';
        }
        cout << endl;
    }
}

void TRY(int i)
{
    int top = n - curr_sum;
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
            if (curr_sum < n)
                TRY(i + 1);
        }
        curr_sum -= j;
    }
}

void solve()
{
    cin >> k >> n;
    int top = n / 2;
    for (int i = 1; i <= top; i++)
    {
        curr_sum = i;
        x[0] = i;
        TRY(1);
    }
}
int main()
{
    solve();
}