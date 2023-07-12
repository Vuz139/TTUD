#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort(int a[], int i, int j)
{
    if (i < j)
    {
        int pivot = partition(a, i, j);
        quick_sort(a, i, pivot - 1);
        quick_sort(a, pivot + 1, j);
    }
}

int main()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}