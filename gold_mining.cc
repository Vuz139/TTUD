#include <bits/stdc++.h>
using namespace std;

int goldMining(int a[], int n, int L1, int L2)
{
    int res[n]; // Max gold from 0 -> n

    for (int i = 0; i < n; i++)
        res[i] = a[i]; // init res[i] = a[i];

    // Caculate res[i] with i = [L1, L2]
    for (int i = L1; i < L2; i++)
    {
        int max = res[0];
        for (int j = 1; j <= i - L1; j++)
        {
            if (max < res[j])
                max = res[j];
        }
        res[i] = a[i] + max;
    }

    // xet max tu L2 den n
    for (int i = L2; i < n; i++)
    {
        int max = res[i - L2];
        for (int j = i - L2 + 1; j <= i - L1; j++)
        {
            if (max < res[j])
                max = res[j];
        }
        res[i] = a[i] + max;
    }

    // Kiem tra trong doan [n-L1+1; n]
    int ans = res[n - L1];
    for (int i = n - L1 + 1; i < n; i++)
    {
        if (ans < res[i])
            ans = res[i];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, L1, L2;
    cin >> n >> L1 >> L2;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = goldMining(a, n, L1, L2);

    cout << ans;

    return 0;
}