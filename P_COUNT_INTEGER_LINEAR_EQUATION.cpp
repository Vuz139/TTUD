#include <bits/stdc++.h>

using namespace std;

unsigned int n, m;
unsigned int *a;
unsigned int solution;

void backtracking(unsigned int i, unsigned int sum)
{
    unsigned int s = sum;
    unsigned int ai = a[i];
    unsigned int remain = (m - s) / ai;
    unsigned int temp;
    for (unsigned int j = 1; j <= remain; j++)
    {
        temp = ai * j;
        s += temp;
        if (i == n - 1)
        {
            if (s == m)
            {

                solution++;
            }

            else
            {
                s = sum;
                continue;
            }
        }
        else
        {
            if (s >= m)
                break;
            else
            {

                backtracking(i + 1, s);
                s = sum;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    a = new unsigned int[n];
    solution = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    backtracking(0, 0);
    cout << solution;
}