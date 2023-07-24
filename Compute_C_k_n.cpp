#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e3 - 1;
int N, k;
vector<vector<int>> combinations;

int to_hop(int n, int k)
{
    if (combinations[n][k] != 0)
        return combinations[n][k];
    if (k == n - 1 || k == 1)
    {
        combinations[n][k] = n;
        return n;
    }
    else if (k == 0 || k == n)
    {
        combinations[n][k] = 1;
        return 1;
    }

    else
    {

        int temp = to_hop(n - 1, k - 1) + to_hop(n - 1, k);
        combinations[n][k] = temp % (int)(1e9 + 7);
        return combinations[n][k];
    }
}

int main()
{
    cin >> k >> N;
    combinations.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        combinations[i].resize(N + 1, 0);
    }
    cout << to_hop(N, k) << endl;
}