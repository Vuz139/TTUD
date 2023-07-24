#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int l1, l2;
    cin >> l1 >> l2;
    // vector<int> amounts(n);
    int amounts[n + 5];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> amounts[i];
    }
    int max;
    deque<int> result;
    for (i = 0; i < l1; i++)
    {
        result.push_back(amounts[i]);
    }
    for (i = l1; i < l2; i++)
    {
        max = -1;
        for (int j = i - l1; j >= 0; j--)
        {
            if (max < result[j])
            {
                max = result[j];
            }
        }
        result.push_back(max + amounts[i]);
    }
    int len = l2 - l1;
    for (i = l2; i < n; i++)
    {
        max = -1;
        for (int j = 0; j <= len; j++)
        {
            if (max < result[j])
            {
                max = result[j];
            }
        }
        result.pop_front();
        result.push_back(max + amounts[i]);
    }
    max = -1;
    for (i = 0; i <= l2; i++)
    {
        if (max < result[i])
        {
            max = result[i];
        }
    }
    cout << max;
}