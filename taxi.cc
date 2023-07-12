#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> s;
int k;

void solve()
{
    cin >> n;
    s.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [](int a, int b)
         { return a > b; });
    int l = n - 1, curr = 0;
    int soxe = 0;
    for (int i = 0; i <= l; i++)
    {
        curr = s[i];
        while (1)
        {
            curr += s[l];
            if (curr <= 5 && i < l)
            {
                l--;
            }
            else
            {
                soxe++;
                break;
            }
        }
    }
    cout << soxe << endl;
}

int main()
{
    freopen("input.inp", "r", stdin);
    solve();
    return 0;
}