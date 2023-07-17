#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int x, y;
    cin >> n;
    vector<int> list_x;
    vector<int> list_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> x >> y;
            list_x.push_back(x);
            list_y.push_back(y);
        }
    }
    int x_min = 101, x_max = -1;
    int y_min = 101, y_max = -1;
    for (int v : list_x)
    {
        x_min = min(x_min, v);
        x_max = max(x_max, v);
    }
    for (int v : list_y)
    {
        y_min = min(y_min, v);
        y_max = max(y_max, v);
    }
    cout << (y_max - y_min) * (x_max - x_min) << endl;
}