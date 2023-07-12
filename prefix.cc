#include <bits/stdc++.h>
using namespace std;
string solve(int arr[], int n)
{
    if (n < 1)
        return "NO";
    if (n == 1)
        return "YES";
    long long prefix[n + 1];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    if (prefix[n - 1] - prefix[0] == 0 || prefix[n - 2] == 0)
        return "YES";
    for (int i = 1; i < n - 1; i++)
    {
        if (prefix[i - 1] == prefix[n - 1] - prefix[i])
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    // freopen("input.inp", "r", stdin);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n);
    return 0;
}