#include <bits/stdc++.h>

using namespace std;

int check_sequence_equal()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    int temp, i;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for (i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    if (n != m)
        return 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int main()
{
    int T;

    cin >> T;
    int x[T + 1];

    for (int i = 0; i < T; i++)
    {
        x[i] = check_sequence_equal();
    }
    for (int i = 0; i < T; i++)
    {
        cout << x[i] << endl;
    }
}
