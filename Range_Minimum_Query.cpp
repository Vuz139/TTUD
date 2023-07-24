#include <bits/stdc++.h>

using namespace std;
const int MAXX = 1e6 + 1;
int n, a[MAXX];
int numOfQuery;
vector<vector<int>> m;
int processing(int i, int j)
{
    int k = log2(j - i + 1);
    // cout << "i, j, log: " << i << "," << j << "," << k << endl;
    if (a[m[k][i]] <= a[m[k][j - (int)pow(2, k) + 1]])
    {
        // cout << "Offset: " << m[k][i] << endl;
        return a[m[k][i]];
    }
    else
    {
        // cout << "Offset: " << m[k][j - (int)pow(2, k) + 1] << endl;

        return a[m[k][j - (int)pow(2, k) + 1]];
    }
}
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int jTemp = (int)log2(n) + 1;

    m.resize(jTemp);
    for (int i = 0; i <= jTemp; i++)
    {
        m[i].resize(n);
    }
    for (int i = 0; i < n; i++)
    {
        m[0][i] = i;
    }

    for (int j = 1; pow(2, j) <= n; j++)
    {

        int jTemp = pow(2, j) - 1;
        int jTemp2 = pow(2, j - 1);
        for (int i = 0; i + jTemp < n; i++)
        {
            if (a[m[j - 1][i]] < a[m[j - 1][jTemp2 + i]])
            {
                m[j][i] = m[j - 1][i];
            }
            else
            {
                m[j][i] = m[j - 1][jTemp2 + i];
            }
        }
    }
    int sum = 0;

    cin >> numOfQuery;
    int start, end;
    for (int i = 0; i < numOfQuery; i++)
    {
        cin >> start >> end;
        sum += processing(start, end);
    }
    cout
        << sum;
}
int main()
{

    // freopen("input.inp", "r", stdin);
    // freopen("output.outp", "w", stdout);
    input();
}
