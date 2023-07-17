#include <bits/stdc++.h>
using namespace std;
int n, L, m;
set<int> keys;
string prefixs_[32];
void compute_prefix()
{
    prefixs_[0] = "0";
    for (int i = 1; i < 32; i++)
    {
        prefixs_[i] = prefixs_[i - 1] + "0";
    }
}

int main()
{
    cin >> n >> L >> m;
    compute_prefix();
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        int s = stoi(temp);
        keys.insert(s);
    }
    int i = 1;
    while (m > 0)
    {
        if (keys.insert(i).second)
        {
            m--;
        }
        i++;
    }
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        int temp = *it;
        string key = to_string(temp);
        if (key.length() < L)
        {
            cout << prefixs_[L - key.length() - 1];
        }
        cout << key << endl;
    }
    return 1;
}