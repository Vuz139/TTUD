#include <bits/stdc++.h>

using namespace std;
vector<int> a;

bool find(int l, int r, int x)
{
    // binary search
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            return true;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (find(j + 1, n - 1, k - a[i] - a[j]))
            {
                count++;
            }
        }
    }
    cout << count;
    return 1;
}