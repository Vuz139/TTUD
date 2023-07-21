#include <bits/stdc++.h>

using namespace std;

int n;
int x[21];
void solution()
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}
void TRY(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n - 1)
        {
            solution();
        }
        else
        {

            TRY(i + 1);
        }
    }
}

int main()
{
    cin >> n;
    TRY(0);
}