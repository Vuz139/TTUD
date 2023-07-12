#include <bits/stdc++.h>
using namespace std;

const int MAX_ = 1e5 + 1;

unsigned int n;
unsigned int a[MAX_];
unsigned int sum_subArr[MAX_];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sum_subArr[0] = a[0];
    sum_subArr[1] = a[1];
    int curr_max_sub = sum_subArr[0];
    for (int i = 2; i < n; i++)
    {

        sum_subArr[i] = curr_max_sub + a[i];
        if (curr_max_sub < sum_subArr[i - 1])
        {
            curr_max_sub = sum_subArr[i - 1];
        }
    }

    if (curr_max_sub < sum_subArr[n - 1])
        cout << sum_subArr[n - 1];
    else
    {
        cout << curr_max_sub << endl;
    }
}
int main()
{
    freopen("../input.inp", "r", stdin);
    // freopen("../output.oup", "w", stdout);

    solve();
}