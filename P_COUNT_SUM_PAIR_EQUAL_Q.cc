#include <bits/stdc++.h>

using namespace std;
int n, Q;
vector<unsigned int> arr;
map<unsigned int, int> m;

void solve()
{
    cin >> n >> Q;
    unsigned int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        m[temp] = 1;
    }

    unsigned int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (m[Q - arr[i]])
        {
            count++;
        }
    }
    cout << count / 2 << endl;
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}
