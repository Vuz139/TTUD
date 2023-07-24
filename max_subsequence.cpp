#include <bits/stdc++.h>

using namespace std;

int max_weight_of_subsequence(int arr[], int n)
{
    int max = INT_MIN;
    int current_max = 0;
    for (int i = 0; i < n; i++)
    {

        current_max += arr[i];
        if (current_max < 0)
        {
            current_max = 0;
        }
        if (max < current_max)
        {
            max = current_max;
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_weight_of_subsequence(a, n);
}