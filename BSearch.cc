#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int bSearch(int s, int e, int x)
{
    if (s == e)
    {
        if (a[s] == x)
            return s;
        else
            return -1;
    }
    else
    {
        int mid = (s + e) / 2;
        if (x > a[mid])
            return bSearch(mid + 1, e, x);
        else if (x == a[mid])
            return mid;
        else
            return bSearch(s, mid - 1, x);
    }
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x;
    cin >> x;
    cout << bSearch(0, n - 1, x) << endl;
}