#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int N, C;

bool check(int distance)
{
    int cnt = 1;
    int last = arr[0];
    for (int i = 1; i < N; ++i)
    {
        if (arr[i] - last >= distance)
        {
            last = arr[i];
            cnt = cnt + 1;
        }
        if (cnt >= C)
            return true;
    }
    return false;
}

void solve()
{
    cin >> N >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int low = 0, high = arr[N - 1] - arr[0];
    int dis = INT_MIN;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (check(mid))
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {

        solve();
        arr.clear();
    }
}
